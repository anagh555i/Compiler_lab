%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<string.h>
    #include "tree.h"
    #include "codeGen.h"

    // forbidden type for paramteres

    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();
    void installFunction(node* f);
    void functionPreperation(Gsymbol *funct);
    bool isArithmetic(node* left, node* right);
    bool isBoolean(node* left, node* right);
    void prerequisites();
    void installDefaultTypes();
    void printTypes();

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    Lsymbol* Lhead=NULL; // global symbol table head
    Gsymbol* currFunction=NULL; // current function global symbol entry which is used in codeGen();
    Typetable* Types=NULL; // type table for the program;
    Fieldlist* Fields=NULL; // field list for the program;

    Typetable* POINTERTYPE=NULL;
    Typetable* VOIDTYPE=NULL;
    Typetable* INTTYPE=NULL;
    Typetable* STRINGTYPE=NULL;
    Typetable* ARRAYTYPE=NULL;
    Typetable* BOOLTYPE=NULL;

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int flabel=1;
    int WHILELABELS[]={-1,-1};// new list based while labels storage required
    Lnode* breakLabels=NULL;
    Lnode* continueLabels=NULL;
    node* functions=NULL;
%}

%start sourceCode
%union{
    int Int;
    char Char;
    struct node* nodePtr;
    char* String;
    struct Lnode* listPtr;
    struct Fieldlist* fieldPtr;
    struct Typetable* typePtr;
    struct typeCapsule* typeCapsule;
}
%token begin
%token end
%token READ 
%token WRITE
%token GE 
%token LE 
%token EQ 
%token NEQ
%token AND
%token OR
%token IF 
%token Else 
%token WHILE
%token DO
%token BREAK
%token CONTINUE
%token REPEAT
%token UNTIL
/* %token INT
%token STR */
%token VOID
%token DECL
%token ENDDECL 
%token RETURN
%token TYPE
%token ENDTYPE
%token MALLOC
%token ARROW
%token Null

%token <Int> NUM
%token <String> ID
%token <String> LITERAL 
%token <String> MAIN

%type <nodePtr> Expr
%type <nodePtr> ArgList
%type <nodePtr> Slist
%type <nodePtr> Stmt
%type <nodePtr> InputStmt
%type <nodePtr> OutputStmt
%type <nodePtr> AssgStmt
%type <nodePtr> ReturnStmt
%type <nodePtr> Ifstmt
%type <nodePtr> LoopStmt
%type <nodePtr> Body
%type <nodePtr> GDelcarations

%type <listPtr> VarList
%type <nodePtr> GDecl
%type <nodePtr> GDecList
%type <listPtr> ArrList
%type <nodePtr> Array
%type <nodePtr> Var

%type <listPtr> ParamList
%type <listPtr> Param

/* %type <Int> Type */
%type <typePtr> VarType

%type <nodePtr> FDefBlock
%type <nodePtr> Fdef

%type <listPtr> IdList
%type <fieldPtr> Field
%type <fieldPtr> FieldList


%left OR
%left AND
%left '<'
%left '>'
%left GE
%left LE
%left EQ
%left NEQ

%left '+'
%left '-'
%left '*'
%left '/'
%left '%' 

%%

sourceCode      :   TypeDeclarations GDelcarations FDefBlock MainBlock {}
                |   TypeDeclarations GDelcarations MainBlock {}   
                ;

TypeDeclarations    :   TYPE Typedefs ENDTYPE   {printTypes(); }
                    |   TYPE ENDTYPE
                    ;
Typedefs            :   Typedefs Typedef
                    |   Typedef
                    ;
Typedef             :   ID '{' FieldList '}'    {   
                                                    if(lookUpType($1)) yyerror("Type already defined");
                                                    InstallType($1,0,NULL);
                                                    Fieldlist* ptr=$3;
                                                    int size=0;
                                                    for(;ptr;ptr=ptr->next){
                                                        Typetable *type=lookUpType(ptr->type->name);
                                                        printf("---- %s %s\n",ptr->name,ptr->type->name);
                                                        if(type==NULL) yyerror("Undefined Type");
                                                        ptr->fieldIndex=size;
                                                        size+=type->size;
                                                        ptr->type=type;
                                                        if(type==POINTERTYPE){
                                                            Typetable *ptrType=lookUpType(ptr->ptrType->name);
                                                            ptr->ptrType=ptrType;
                                                        }
                                                    }
                                                    Types->size=size;
                                                    Types->fields=$3;
                                                }
                    ;
FieldList           :   Field FieldList         {$1->next=$2; $$=$1;}
                    |   Field                   {$$=$1;}
                    ;                
Field               :   ID ID ';'               {
                                                    // don't do type checking yet, do it in Typedef
                                                    $$=makeField($2,0,makeTypeNode($1),NULL);
                                                }
                    |   ID '*' ID ';'           {
                                                    // don't do type checking yet, do it in Typedef
                                                    $$=makeField($3,0,makeTypeNode(strdup("pointer")),NULL);
                                                    $$->ptrType=makeTypeNode($1);
                                                }
                    ;

GDelcarations   :       DECL GDecList ENDDECL    {}
                |       DECL ENDDECL            {}
                ;
GDecList        :       GDecl GDecList            {}
                |       GDecl                    {}
                ;
ArrList         :       '[' NUM ']' ArrList     {$$=makeLnode("",$2,$4);} // returns linear chain of dimension
                |       '[' NUM ']'             {$$=makeLnode("",$2,NULL);}
                ;
GDecl           :       VarType VarList ';'         {
                                                  Lnode* ptr=$2;
                                                  if($1->size<1) yyerror("Type cannot be declared");
                                                  for(;ptr;ptr=ptr->next){
                                                    if(lookUpG(ptr->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                    }
                                                    if(ptr->num==valtype){
                                                        installG(ptr->s,$1,$1->size,SP);
                                                        SP+=($1->size);
                                                    }
                                                    else{
                                                        installG(ptr->s,POINTERTYPE,1,SP++); // Pointer is of size 1
                                                        Ghead->ptrType=$1;
                                                    }
                                                  }
                                                }
                |       VarType ID ArrList';'       {
                                                    if($1->size<1) yyerror("Type cannot be declared");
                                                    if(lookUpG($2)) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=$1->size;
                                                    Lnode* ptr=$3;
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    installG($2,ARRAYTYPE,size,SP);
                                                    SP+=size;
                                                    // Gsymbol* g=lookUpG($2);
                                                    Ghead->dim=makeLnode("",dim,$3);
                                                    Ghead->ptrType=$1;
                                                }
                |       VarType ID '(' ParamList ')'';'    {
                                                            if(lookUpG($2)) yyerror("variable already declared");
                                                            if($1->size>1) yyerror("return type of size>1 not yet possible");
                                                            installG($2,$1,0,0);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
                |       VarType'*' ID '(' ParamList ')'';'  {
                                                            if($1->size<1) yyerror("pointer of Type cannot be declared");
                                                            if(lookUpG($3)) yyerror("variable already declared");
                                                            installG($3,POINTERTYPE,0,0);
                                                            Ghead->ptrType=$1;
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
                ;
VarList         :       ID ',' VarList          {$$=makeLnode($1,valtype,$3);}
                |       '*'ID ',' VarList       {$$=makeLnode($2,ptrtype,$4);} // list num stores type of variable
                |       ID                      {$$=makeLnode($1,valtype,NULL);}
                |       '*'ID                   {$$=makeLnode($2,ptrtype,NULL);} 
                ;

ParamList   : Param ',' ParamList   {} 
            | Param                 {}
            |/*param can be empty*/ {}
            ;
Param       : VarType ID            {   //printf("Type type=%d\n",$1);
                                        // if($1 != inttype && $1!=strtype && $1!=intptrtype && $1!=strptrtype) yyerror("forbidden type for paramteres");
                                        if($1->size<1) yyerror("Type cannot be declared");
                                        if(lookUpL($2)) yyerror("duplicate parameter");
                                        installL($2,$1,NULL,-1); // add parameter to Lhead 
                                    } 
            | VarType '*' ID        {   //printf("Type type=%d\n",$1);
                                        if($1->size<1) yyerror("Pointer Type cannot be declared");
                                        if(lookUpL($3)) yyerror("duplicate parameter");
                                        installL($3,POINTERTYPE,$1,-1); // add parameter to Lhead 
                                    } 
            ;

VarType     : ID        {
                            Typetable* type=lookUpType($1);
                            if(type==NULL) yyerror("undefined type");
                            $$=type;
                        }
            | VOID      {
                            $$=VOIDTYPE;
                        }
            ;

FDefBlock   : FDefBlock Fdef 
            | Fdef
            ;

Fdef        : VarType ID '(' ParamList ')''{' LdeclBlock Body '}'  {/*iterate through paramlist and Lhead and check correctness and assign relative binding*/
                                                                    Gsymbol* funct=lookUpG($2);
                                                                    if(!funct || funct->flabel==-1) yyerror("undeclared function");
                                                                    if(funct->type!=$1) yyerror("type mismatch in funciton decl and def");
                                                                    Lsymbol* ptr;
                                                                    int offset=-3;
                                                                    ptr=funct->paramlist;
                                                                    funct->paramlist=Lhead;
                                                                    for(;ptr && Lhead;ptr=ptr->next){
                                                                        if(ptr->type!=Lhead->type) yyerror("conflicting function declaration and definition");
                                                                        if(strcmp(ptr->name,Lhead->name)!=0)yyerror("conflicting function declaration and definition");
                                                                        Lhead->binding=offset--;
                                                                        Lhead=Lhead->next;
                                                                    }
                                                                    // original funct->paramlist from declaration is not used anymore, maybe used for future polymorphism implementations
                                                                    // funct->paramlist already contains all the parameters and local declarations
                                                                    // now the rest of Lhead is local variables
                                                                    offset=1;
                                                                    funct->fsymbols=Lhead;
                                                                    for(;Lhead;Lhead=Lhead->next){
                                                                        Lhead->binding=offset++;
                                                                    }
                                                                    installFunction(makeNode(0,funct->type,funct,funct->paramlist,tFUNCT,NULL,$8,NULL)); //->right points to function definition and left to next function 
                                                                    Lhead=NULL;
                                                                }
            | VarType '*' ID '(' ParamList ')''{' LdeclBlock Body '}'  {/*iterate through paramlist and Lhead and check correctness and assign relative binding*/
                                                                    if($1->size<1) yyerror("pointer of Type cannot be declared");
                                                                    Gsymbol* funct=lookUpG($3);
                                                                    if(!funct || funct->flabel==-1) yyerror("undeclared function");
                                                                    if(funct->type!=POINTERTYPE) yyerror("type mismatch in funciton decl and def");
                                                                    Lsymbol* ptr;
                                                                    int offset=-3;
                                                                    ptr=funct->paramlist;
                                                                    funct->paramlist=Lhead;
                                                                    for(;ptr && Lhead;ptr=ptr->next){
                                                                        if(ptr->type!=Lhead->type) yyerror("conflicting function declaration and definition");
                                                                        if(strcmp(ptr->name,Lhead->name)!=0)yyerror("conflicting function declaration and definition");
                                                                        Lhead->binding=offset--;
                                                                        Lhead=Lhead->next;
                                                                    }
                                                                    // original funct->paramlist from declaration is not used anymore, maybe used for future polymorphism implementations
                                                                    // funct->paramlist already contains all the parameters and local declarations
                                                                    // now the rest of Lhead is local variables
                                                                    offset=1;
                                                                    funct->fsymbols=Lhead;
                                                                    for(;Lhead;Lhead=Lhead->next){
                                                                        Lhead->binding=offset++;
                                                                    }
                                                                    installFunction(makeNode(0,funct->type,funct,funct->paramlist,tFUNCT,NULL,$9,NULL)); //->right points to function definition and left to next function 
                                                                    Lhead=NULL;
                                                                }
            ;

MainBlock        : VOID MAIN '('')''{' LdeclBlock Body '}'  {
                                                                if(lookUpG($2)) yyerror("only one main function allowed");
                                                                installG($2,VOIDTYPE,0,0);
                                                                Ghead->flabel=0; // assign label and mark variable as function 
                                                                Ghead->paramlist=Lhead;
                                                                Ghead->fsymbols=Lhead;
                                                                int offset=1;
                                                                for(;Lhead;Lhead=Lhead->next){
                                                                    Lhead->binding=offset++;
                                                                }
                                                                installFunction(makeNode(0,VOIDTYPE,Ghead,Ghead->paramlist,tFUNCT,NULL,$7,NULL));
                                                                Lhead=NULL;
                                                            }
            ;
LdeclBlock  : DECL LDecList ENDDECL 
            | DECL ENDDECL
            | //no declarations
            ;
LDecList    : LDecl LDecList  
            | LDecl
            ;
LDecl       : VarType IdList ';'   {
                                    Lnode* ptr=$2;
                                    if($1->size<1) yyerror("Type cannot be declared");
                                    for(;ptr;ptr=ptr->next){
                                        if(lookUpL(ptr->s)) yyerror("variable already declared");
                                        if(ptr->num == valtype){
                                            installL(ptr->s,$1,NULL,-1);
                                        }
                                        else{
                                            installL(ptr->s,POINTERTYPE,$1,-1);
                                        }
                                    }
                                }
            ;
IdList      : ID ',' IdList     {$$=makeLnode($1,valtype,$3);}
            | '*' ID ',' IdList {$$=makeLnode($2,ptrtype,$4);}
            | ID                {$$=makeLnode($1,valtype,NULL);}
            | '*' ID            {$$=makeLnode($2,ptrtype,NULL);}
            ;


Body    :   begin Slist  ReturnStmt ';' end     {$$=makeNode(0,NULL,NULL,NULL,tCONNECT,$2,$3,NULL);}
        |   begin ReturnStmt ';' end            {$$=$2;}
        ;
Slist   :   Slist Stmt              {$$=makeNode(0,NULL,NULL,NULL,tCONNECT,$1,$2,NULL);}
        |   Stmt                    {$$=$1;}
        ;
Stmt    :   InputStmt ';'           {$$=$1;}
        |   OutputStmt ';'          {$$=$1;}
        |   AssgStmt ';'            {$$=$1;}
        |   ReturnStmt ';'          {$$=$1;}
        |   Ifstmt                  {$$=$1;}
        |   LoopStmt                {$$=$1;}
        |   BREAK ';'               {$$=makeNode(0,NULL,NULL,NULL,tBREAK,NULL,NULL,NULL);}
        |   CONTINUE ';'            {$$=makeNode(0,NULL,NULL,NULL,tCONTINUE,NULL,NULL,NULL);}
        ;
ReturnStmt  :   RETURN Expr         {$$=makeNode(0,NULL,NULL,NULL,tRETURN,$2,$2,$2);} // do semantic analysis while codeGen
            |   RETURN              {$$=makeNode(0,NULL,NULL,NULL,tRETURN,NULL,NULL,NULL);} // null means void return 
            ;
LoopStmt    :   WHILE '(' Expr ')' '{' Slist '}'    {if(isBoolean($3,$3)) $$=makeNode(0,NULL,NULL,NULL,tWHILE,$6,$6,$3);}
            |   DO '{' Slist '}' WHILE '(' Expr ')'             {if(isBoolean($7,$7)) $$=makeNode(0,NULL,NULL,NULL,tDOWHILE,$3,$3,$7);}
            |   REPEAT '{' Slist '}' UNTIL '(' Expr ')'             {if(isBoolean($7,$7)) $$=makeNode(0,NULL,NULL,NULL,tREPEATUNTIL,$3,$3,$7);}
            ;
Ifstmt  :   IF '('Expr')' '{' Slist '}' Else '{' Slist '}'   {if(isBoolean($3,$3)) $$=makeNode(0,NULL,NULL,NULL,tIF,$6,$10,$3);}
        |   IF '('Expr')' '{' Slist '}'             {if(isBoolean($3,$3)) $$=makeNode(0,NULL,NULL,NULL,tIF,$6,NULL,$3);}
        ;/* ;   center->condition, left->iftrue, right-> else */
InputStmt   :   READ '(' ID ')'     { //////ADJUST FOR VAR
                                    Gsymbol* Gptr=lookUpG($3);
                                    Lsymbol* Lptr=lookUpL($3);
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared Variable");
                                    node* temp=makeNode(0,NULL,Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    $$=makeNode(0,NULL,NULL,NULL,tREAD,temp,temp,NULL);
                                    }
            ;
OutputStmt  :   WRITE '(' Expr ')'  {$$=makeNode(0,NULL,NULL,NULL,tWRITE,$3,$3,NULL);}
            ;
AssgStmt    :   Var '=' Expr        {
                                    printf("types: %s\n",$1->right->type->name);
                                    printf("types: %s\n",$3->type->name);
                                    if($1->right->type!=$3->type) yyerror("assignment type mismatch");
                                    $$=makeNode(0,NULL,NULL,NULL,tASSIGN,$1,$3,NULL);
                                    }
            |   '*'Var '=' Expr     {
                                    if($2->right->type!=POINTERTYPE) yyerror("pointer assignment type mismatch");
                                    if($2->right->ptrType!=$4->type) yyerror("Pointer type mismatch");
                                    node* ptr=makeNode(0,NULL,NULL,NULL,tGETADDRATVAL,$2,NULL,NULL);
                                    $$=makeNode(0,NULL,NULL,NULL,tASSIGN,ptr,$4,NULL);
                                    }
            |   ID Array '=' Expr   {
                                        Gsymbol* ptr=lookUpG($1); // no need to look at local variable as array is only declared in global
                                        if(!ptr) yyerror("variable undeclared");
                                        if(ptr->type!=ARRAYTYPE) yyerror("array access forbidden for variable");
                                        if(ptr->ptrType!=$4->type) yyerror("assignment type mismatch");
                                        node* var=NULL;
                                        var=makeNode(0,ptr->ptrType,ptr,NULL,tARRADDR,$2,$2,$2);
                                        // if(ptr->type==intarrtype) var=makeNode(0,inttype,ptr,NULL,tARRVAL,$2,$2,$2);
                                        // else if(ptr->type==strarrtype) var=makeNode(0,strtype,ptr,NULL,tARRVAL,$2,$2,$2);
                                        // if(var->type!=$4->type) yyerror("type mismatch");
                                        $$=makeNode(0,NULL,NULL,NULL,tASSIGN,var,$4,$4);
                                    }
            ;
Array   :       '[' Expr ']' Array     {if(isArithmetic($2,$2)){
                                            $2->left=$4;
                                            $$=$2;
                                        }
                                      } 
        |       '[' Expr ']'           {if(isArithmetic($2,$2)) $$=$2;}
        ;

Expr    :   Expr '+' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,INTTYPE,NULL,NULL,tADD,$1,$3,NULL);}
        |   Expr '-' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,INTTYPE,NULL,NULL,tSUB,$1,$3,NULL);}
        |   Expr '*' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,INTTYPE,NULL,NULL,tMUL,$1,$3,NULL);}
        |   Expr '/' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,INTTYPE,NULL,NULL,tDIV,$1,$3,NULL);}
        |   Expr '%' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,INTTYPE,NULL,NULL,tMOD,$1,$3,NULL);}
        |   Expr '>' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tGT,$1,$3,NULL);} 
        |   Expr '<' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tLT,$1,$3,NULL);} 
        |   Expr GE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tGE,$1,$3,NULL);} 
        |   Expr LE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tLE,$1,$3,NULL);} 
        |   Expr EQ Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tEQ,$1,$3,NULL);} 
        |   Expr NEQ Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tNEQ,$1,$3,NULL);} 
        |   Expr AND Expr           {if(isBoolean($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tAND,$1,$3,NULL);} 
        |   Expr OR Expr            {if(isBoolean($1,$3)) $$=makeNode(0,BOOLTYPE,NULL,NULL,tOR,$1,$3,NULL);} 
        |   '(' Expr ')'            {$$=$2;}
        |   ID '(' ArgList ')'       {
                                        Gsymbol* fg=lookUpG($1);
                                        if(!fg) yyerror("function not defined");
                                        node* ptr=$3;
                                        Lsymbol* ld=fg->paramlist;
                                        for(;ptr && ld;ld=ld->next,ptr=ptr->center){
                                            if(ptr->type!=ld->type) {
                                                printf("%s, %s %s\n",ptr->type->name,ld->name,ld->type->name);
                                                yyerror("type mismatch");
                                            }
                                        }
                                        if(ptr) yyerror("error in argument list");
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        $$=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,$3,NULL,NULL); //left contains argument list for function call
                                    }
        |   ID'('')'                {
                                        Gsymbol* fg=lookUpG($1);
                                        if(!fg) yyerror("function not defined");
                                        Lsymbol* ld=fg->paramlist;
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        $$=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,NULL,NULL,NULL); //left contains argument list for function call
                                    }
        |   NUM                     {$$=makeNode($1,INTTYPE,NULL,NULL,tCONST,NULL,NULL,NULL);}
        |   '-' NUM                 {$$=makeNode(-1*$2,INTTYPE,NULL,NULL,tCONST,NULL,NULL,NULL);}
        |   LITERAL                 {
                                     printf("STARTED parsing literal");
                                     $$=makeNode(0,STRINGTYPE,NULL,NULL,tLITERAL,NULL,NULL,NULL);
                                     $$->literal=$1;
                                     printf("FINISHED parsing literal");
                                    }
        |   Var                     {
                                    $$=makeNode(0,$1->right->type,NULL,NULL,tGETVAL,$1,NULL,NULL);
                                    $$->ptrType=$1->right->ptrType;
                                    }
        |  '&' Var                  {
                                    $$=$2;
                                    }
        |  '*' Var                  {
                                    if($2->right->type!=POINTERTYPE) yyerror("not pointer variable");
                                    $$=makeNode(0,$2->right->ptrType,NULL,NULL,tVALUEAT,$2,NULL,NULL);
            /////////////////////////////////////
                                    // Gsymbol* Gptr=lookUpG($2);
                                    // Lsymbol* Lptr=lookUpL($2);
                                    // if(Gptr==NULL && Lptr==NULL) yyerror("undeclared variable");
                                    // node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL); 
                                    // if(Lptr && Lptr->type==intptrtype)$$=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    // else if(Lptr && Lptr->type==strptrtype) $$=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    // else if(Gptr->type==intptrtype)$$=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    // else if(Gptr->type==strptrtype) $$=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    }
        |   ID Array            {
                                    Gsymbol* ptr=lookUpG($1);
                                    if(!ptr) yyerror("variable undeclared");
                                    if(ptr->type!=ARRAYTYPE) yyerror("type mismatch");
                                    $$=makeNode(0,ptr->ptrType,ptr,NULL,tARRVAL,$2,$2,$2);
                                }
        |   MALLOC '(' VarType ')'  {
                                        $$=makeNode(0,POINTERTYPE,NULL,NULL,tMALLOC,NULL,NULL,NULL);
                                        $$->ptrType=$3;
                                    }
        |   Null                {
                                    $$=makeNode(0,POINTERTYPE,NULL,NULL,tNULL,NULL,NULL,NULL);
                                }
        ;
Var     :   Var '.' ID      {
                                printf("##\n");
                                if($1->right->type==POINTERTYPE) yyerror("Static access from pointer variable");  
                                printf("##\n");
                                Fieldlist* field=LookupField($1->right->type,$3); 
                                printf("##\n");
                                if(field==NULL) yyerror("NO such field");  
                                printf("##\n");
                                node* var=makeNode(field->fieldIndex,field->type,NULL,NULL,tCONST,NULL,NULL,NULL); 
                                printf("##\n");
                                var->ptrType=field->ptrType; 
                                printf("##\n");
                                $$=makeNode(0,POINTERTYPE,NULL,NULL,tRECURSADDR,$1,var,NULL) ;                   
                            }
        |   Var ARROW ID   {
                                printf("##\n");
                                if($1->right->type!=POINTERTYPE) yyerror("pointer access from static type");
                                printf("##\n");
                                printf("x->%s type: %s\n",$3,$1->right->type->name);
                                printf("%s\n",$1->right->ptrType->name);
                                Fieldlist* field=LookupField($1->right->ptrType,$3);
                                printf("field name: %s\n",field->name);
                                if(field==NULL) yyerror("NO such field");
                                node* var=makeNode(field->fieldIndex,field->type,NULL,NULL,tCONST,NULL,NULL,NULL);
                                var->ptrType=field->ptrType;
                                $$=makeNode(0,POINTERTYPE,NULL,NULL,tRECURSADDRATVAL,$1,var,NULL) ;
                            }
        |   ID              {
                                printf("From expr %s\n",$1);
                                Gsymbol* Gptr=lookUpG($1);
                                Lsymbol* Lptr=lookUpL($1);
                                if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                var->ptrType=Lptr?Lptr->ptrType:Gptr->ptrType;
                                $$=makeNode(0,POINTERTYPE,NULL,NULL,tADDRESSOF,var,var,NULL) ;
                                $$->ptrType=Lptr?Lptr->type:Gptr->type;
                            }
        ;

ArgList : Expr',' ArgList   {   // argument list will be linked with center pointer
                                $1->center=$3;
                                $$=$1;
                            }
        | Expr              {$$=$1;}
        ;

%%

int main(){
    FILE *fp=fopen("ExtendedEuclidean.c","r");
    outFile=fopen("a.xsm","w");
    yyin=fp;
    SP=4096;
    installDefaultTypes();
    yyparse();
    Gsymbol* ptr=Ghead;
    if(!ptr) printf("What\n");
    for(;ptr;ptr=ptr->next)printf("%s ",ptr->name);
    printf("parsing complete\n");

    space=0;
    /* printTree(root); */

    genHeader();
    prerequisites(); // set stack pointer to after declarations
    
    printf("functions\n");
    for(;functions;functions=functions->left){
        printf("#######\n");
        continueLabels=NULL;
        breakLabels=NULL;
        Lhead=functions->Lvar;
        currFunction=functions->Gvar;
        currReg=0;
        functionPreperation(currFunction);
        /* printf("function preperation done %s\n",currFunction->name); */
        genCode(functions->right);
    }
    /* int reg=genCode(root); */
    printf("codeGen completed\n");
    genSegmenationFault();
    genErrorHandler();
    genExit();
    return 0;
}

void printTypes(){
    Typetable* ptr =Types;
    for(;ptr!=NULL;ptr=ptr->next){
        printf("\ntype: %s\n",ptr->name);
        Fieldlist * f=ptr->fields;
        for(;f!=NULL;f=f->next){
            printf("%s ",f->name);
        }
    }
}

//fsymbol

void yyerror(char* s){
    printf("******************* Compilation error ******************\n");
    printf("%s\n",s);
    printf("********************************************************\n");
    exit(0);
}

void installDefaultTypes(){
    InstallType(strdup("void"),0,NULL);
    VOIDTYPE=Types;
    InstallType(strdup("int"),1,NULL);
    INTTYPE=Types;
    InstallType(strdup("string"),1,NULL);
    STRINGTYPE=Types;
    InstallType(strdup("pointer"),1,NULL);
    POINTERTYPE=Types;
    InstallType(strdup("array"),1,NULL);
    ARRAYTYPE=Types;
    InstallType(strdup("bool"),1,NULL);
    ARRAYTYPE=Types;
}

void functionPreperation(Gsymbol *funct){
    fprintf(outFile,"F%d:\n",funct->flabel);
    fprintf(outFile,"PUSH BP\n");
    fprintf(outFile,"MOV BP, SP\n");
    Lsymbol* lvar=funct->fsymbols;
    fprintf(outFile,"MOV R0,0\n");
    for(;lvar;lvar=lvar->next) fprintf(outFile,"PUSH R0\n");
    printf("okay function prepared\n");
}

void installFunction(node* f){
    f->left=functions;
    functions=f;
}// left left chain of functions

void prerequisites(){
    fprintf(outFile,"MOV SP,%d\n",SP); // set stack pointer to after the declarations;
    fprintf(outFile,"MOV BP,%d\n",SP); // set base pointer to top of stack
    initializeHeapSet();
    fprintf(outFile,"MAIN:\n");
    fprintf(outFile,"CALL F0!\n");
    fprintf(outFile,"JMP EXITCODE!\n");
}

bool isArithmetic(node* left, node* right){
    if(left==NULL || right==NULL){
        yyerror("syntax error");
        exit(0);
    }
    if(left->type!=right->type){
        yyerror("type mismatch");
        exit(0);
    }
    return true;
}
bool isBoolean(node* left, node* right){
    if(left==NULL || right==NULL){
        yyerror("syntax error");
        exit(0);
    }
    if(left->type!= BOOLTYPE || right->type!=BOOLTYPE){
        yyerror("type mismatch");
        exit(0);
    }
    return true;
}

