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

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    Lsymbol* Lhead=NULL; // global symbol table head
    Gsymbol* currFunction=NULL; // current function global symbol entry which is used in codeGen();

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
%token INT
%token STR
%token VOID
%token DECL
%token ENDDECL 
%token RETURN

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

%type <listPtr> ParamList
%type <listPtr> Param

%type <Int> Type

%type <nodePtr> FDefBlock
%type <nodePtr> Fdef

%type <listPtr> IdList

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

sourceCode      :   GDelcarations FDefBlock MainBlock {}
                |   GDelcarations MainBlock {}   
                ;

GDelcarations   :       DECL GDecList ENDDECL    {}
                |       DECL ENDDECL            {}
                ;
GDecList        :       GDecList GDecl            {}
                |       GDecl                    {}
                ;
ArrList         :       '[' NUM ']' ArrList     {$$=makeLnode("",$2,$4);} // returns linear chain of dimension
                |       '[' NUM ']'             {$$=makeLnode("",$2,NULL);}
                ;
GDecl           :       Type VarList ';'         {
                                                  Lnode* ptr=$2;
                                                  for(;ptr;ptr=ptr->next){
                                                    if(lookUpG(ptr->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                    }
                                                    if(ptr->num==valtype) installG(ptr->s,$1,1,SP++);
                                                    else{
                                                        int type;
                                                        if($1==inttype) type=intptrtype;
                                                        else if($1==strtype) type=strptrtype;
                                                        else yyerror("forbidden type for pointer ");
                                                        installG(ptr->s,type,1,SP++);
                                                    }
                                                  }
                                                }
                |       Type ID ArrList';'       {
                                                    if(lookUpG($2)) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=1;
                                                    Lnode* ptr=$3;
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    int type;
                                                    if($1==inttype) type=intarrtype;
                                                    else if($1==strtype) type=strarrtype;
                                                    else yyerror("forbidden array type");
                                                    installG($2,type,size,SP);
                                                    SP+=size;
                                                    Gsymbol* g=lookUpG($2);
                                                    g->dim=makeLnode("",dim,$3);
                                                }
                |       Type ID '(' ParamList ')'';'    {
                                                            if(lookUpG($2)) yyerror("variable already declared");
                                                            installG($2,$1,0,0);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
                ;
VarList         :       VarList ',' ID          {$$=makeLnode($3,valtype,$1);}
                |       VarList ',' '*'ID       {$$=makeLnode($4,ptrtype,$1);} // list num stores type of variable
                |       ID                      {$$=makeLnode($1,valtype,NULL);}
                |       '*'ID                   {$$=makeLnode($2,ptrtype,NULL);} 
                ;

ParamList   : Param ',' ParamList   {} 
            | Param                 {}
            |/*param can be empty*/ {}
            ;
Param       : Type ID               {   printf("Type type=%d\n",$1);
                                        if($1 != inttype && $1!=strtype && $1!=intptrtype && $1!=strptrtype) yyerror("forbidden type for paramteres");
                                        if(lookUpL($2)) yyerror("duplicate parameter");
                                        installL($2,$1,-1); // add parameter to Lhead 
                                    } 
            ;

Type        : INT   {$$=inttype;}
            | STR   {$$=strtype;}
            | VOID  {$$=voidtype;}
            | INT '*'  {$$=intptrtype;}
            | STR '*'  {$$=strptrtype;}
            ;

FDefBlock   : FDefBlock Fdef
            | Fdef
            ;

Fdef        : Type ID '(' ParamList ')''{' LdeclBlock Body '}'  {/*iterate through paramlist and Lhead and check correctness and assign relative binding*/
                                                                    Gsymbol* funct=lookUpG($2);
                                                                    if(!funct || funct->flabel==-1) yyerror("undeclared function");
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
            ;

MainBlock        : VOID MAIN '('')''{' LdeclBlock Body '}'  {
                                                                if(lookUpG($2)) yyerror("only one main function allowed");
                                                                installG($2,voidtype,0,0);
                                                                Ghead->flabel=0; // assign label and mark variable as function 
                                                                Ghead->paramlist=Lhead;
                                                                Ghead->fsymbols=Lhead;
                                                                int offset=1;
                                                                for(;Lhead;Lhead=Lhead->next){
                                                                    Lhead->binding=offset++;
                                                                }
                                                                installFunction(makeNode(0,voidtype,Ghead,Ghead->paramlist,tFUNCT,NULL,$7,NULL));
                                                                Lhead=NULL;
                                                            }
            ;
//type mismatch
LdeclBlock  : DECL LDecList ENDDECL 
            | DECL ENDDECL
            | //no declarations
            ;
LDecList    : LDecList LDecl 
            | LDecl
            ;
LDecl       : Type IdList ';'   {
                                    Lnode* ptr=$2;
                                    for(;ptr;ptr=ptr->next){
                                        if(lookUpL(ptr->s)) yyerror("variable already declared");
                                        installL(ptr->s,$1,-1);
                                    }
                                }
            ;
IdList      : ID ',' IdList     {$$=makeLnode($1,valtype,$3);}
            | ID                {$$=makeLnode($1,valtype,NULL);}
            ;


Body    :   begin Slist  ReturnStmt ';' end     {$$=makeNode(0,0,NULL,NULL,tCONNECT,$2,$3,NULL);}
        |   begin ReturnStmt ';' end            {$$=$2;}
        ;
Slist   :   Slist Stmt              {$$=makeNode(0,0,NULL,NULL,tCONNECT,$1,$2,NULL);}
        |   Stmt                    {$$=$1;}
        ;
Stmt    :   InputStmt ';'           {$$=$1;}
        |   OutputStmt ';'          {$$=$1;}
        |   AssgStmt ';'            {$$=$1;}
        |   ReturnStmt ';'          {$$=$1;}
        |   Ifstmt                  {$$=$1;}
        |   LoopStmt                {$$=$1;}
        |   BREAK ';'               {$$=makeNode(0,0,NULL,NULL,tBREAK,NULL,NULL,NULL);}
        |   CONTINUE ';'            {$$=makeNode(0,0,NULL,NULL,tCONTINUE,NULL,NULL,NULL);}
        ;
ReturnStmt  :   RETURN Expr         {$$=makeNode(0,0,NULL,NULL,tRETURN,$2,$2,$2);} // do semantic analysis while codeGen
            |   RETURN              {$$=makeNode(0,0,NULL,NULL,tRETURN,NULL,NULL,NULL);} // null means void return 
            ;
LoopStmt    :   WHILE '(' Expr ')' '{' Slist '}'    {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,NULL,tWHILE,$6,$6,$3);}
            |   DO '{' Slist '}' WHILE '(' Expr ')'             {if(isBoolean($7,$7)) $$=makeNode(0,0,NULL,NULL,tDOWHILE,$3,$3,$7);}
            |   REPEAT '{' Slist '}' UNTIL '(' Expr ')'             {if(isBoolean($7,$7)) $$=makeNode(0,0,NULL,NULL,tREPEATUNTIL,$3,$3,$7);}
            ;
Ifstmt  :   IF '('Expr')' '{' Slist '}' Else '{' Slist '}'   {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,NULL,tIF,$6,$10,$3);}
        |   IF '('Expr')' '{' Slist '}'             {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,NULL,tIF,$6,NULL,$3);}
        ;/* ;   center->condition, left->iftrue, right-> else */
InputStmt   :   READ '(' ID ')'     {
                                    Gsymbol* Gptr=lookUpG($3);
                                    Lsymbol* Lptr=lookUpL($3);
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared Variable");
                                    node* temp=makeNode(0,0,Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    $$=makeNode(0,0,NULL,NULL,tREAD,temp,temp,NULL);
                                    }
            ;
OutputStmt  :   WRITE '(' Expr ')'  {$$=makeNode(0,0,NULL,NULL,tWRITE,$3,$3,NULL);}
            ;
AssgStmt    :   ID '=' Expr         {
                                    Gsymbol* Gptr=lookUpG($1);
                                    Lsymbol* Lptr=lookUpL($1);
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undelcared variable");
                                    node* temp=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    $$=makeNode(0,0,NULL,NULL,tASSIGN,temp,$3,NULL);
                                    }
            |   '*'ID '=' Expr      {
                                    Gsymbol* Gptr=lookUpG($2);
                                    Lsymbol* Lptr=lookUpL($2);
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undelcared variable");
                                    node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL); 
                                    if(Lptr && Lptr->type==intptrtype)var=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Lptr && Lptr->type==strptrtype) var=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==intptrtype) var=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==strptrtype) var=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    else yyerror("type mismatch");
                                    $$=makeNode(0,0,NULL,NULL,tASSIGN,var,$4,NULL);
                                    }
            |   ID Array '=' Expr {
                                        Gsymbol* ptr=lookUpG($1); // no need to look at local variable as array is only declared in global
                                        if(!ptr) yyerror("variable undeclared");
                                        node* var=NULL;
                                        if(ptr->type==intarrtype) var=makeNode(0,inttype,ptr,NULL,tARRVAL,$2,$2,$2);
                                        else if(ptr->type==strarrtype) var=makeNode(0,strtype,ptr,NULL,tARRVAL,$2,$2,$2);
                                        if(var->type!=$4->type) yyerror("type mismatch");
                                        $$=makeNode(0,inttype,NULL,NULL,tASSIGN,var,$4,$4);
                                    }
            ;
Array   :       '[' Expr ']' Array     {if(isArithmetic($2,$2)){
                                            $2->left=$4;
                                            $$=$2;
                                        }
                                      } 
        |       '[' Expr ']'           {if(isArithmetic($2,$2)) $$=$2;}
        ;

Expr    :   Expr '+' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,NULL,tADD,$1,$3,NULL);}
        |   Expr '-' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,NULL,tSUB,$1,$3,NULL);}
        |   Expr '*' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,NULL,tMUL,$1,$3,NULL);}
        |   Expr '/' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,NULL,tDIV,$1,$3,NULL);}
        |   Expr '%' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,NULL,tMOD,$1,$3,NULL);}
        |   Expr '>' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tGT,$1,$3,NULL);} 
        |   Expr '<' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tLT,$1,$3,NULL);} 
        |   Expr GE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tGE,$1,$3,NULL);} 
        |   Expr LE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tLE,$1,$3,NULL);} 
        |   Expr EQ Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tEQ,$1,$3,NULL);} 
        |   Expr NEQ Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tNEQ,$1,$3,NULL);} 
        |   Expr AND Expr           {if(isBoolean($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tAND,$1,$3,NULL);} 
        |   Expr OR Expr            {if(isBoolean($1,$3)) $$=makeNode(0,booltype,NULL,NULL,tOR,$1,$3,NULL);} 
        |   '(' Expr ')'            {$$=$2;}
        |   ID '(' ArgList ')'       {
                                        Gsymbol* fg=lookUpG($1);
                                        if(!fg) yyerror("function not defined");
                                        node* ptr=$3;
                                        Lsymbol* ld=fg->paramlist;
                                        for(;ptr && ld;ld=ld->next,ptr=ptr->center){
                                            if(ptr->type!=ld->type) yyerror("type mismatch");
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
        |   NUM                     {$$=makeNode($1,inttype,NULL,NULL,tCONST,NULL,NULL,NULL);}
        |   '-' NUM                 {$$=makeNode(-1*$2,inttype,NULL,NULL,tCONST,NULL,NULL,NULL);}
        |   LITERAL                 {
                                     printf("STARTED parsing literal");
                                     $$=makeNode(0,strtype,NULL,NULL,tLITERAL,NULL,NULL,NULL);
                                     $$->literal=$1;
                                     printf("FINISHED parsing literal");
                                    }
        |   ID                      {
                                    printf("From expr %s\n",$1);
                                    Gsymbol* Gptr=lookUpG($1);
                                    Lsymbol* Lptr=lookUpL($1);
                                    if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                    $$=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    }
        |  '&' ID                   {
                                    Gsymbol* Gptr=lookUpG($2);
                                    Lsymbol* Lptr=lookUpL($2);
                                    if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                    node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    $$=makeNode(0,inttype,NULL,NULL,tADDRESSOF,var,var,NULL) ; // i don't see the point of address type, now we can do &var+1 and all
                                    }
        |  '*' ID                   {
                                    Gsymbol* Gptr=lookUpG($2);
                                    Lsymbol* Lptr=lookUpL($2);
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared variable");
                                    node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL); 
                                    if(Lptr && Lptr->type==intptrtype)$$=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Lptr && Lptr->type==strptrtype) $$=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==intptrtype)$$=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==strptrtype) $$=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    }
        |   ID Array            {
                                    Gsymbol* ptr=lookUpG($1);
                                    if(!ptr) yyerror("variable undeclared");
                                    if(ptr->type==intarrtype) $$=makeNode(0,inttype,ptr,NULL,tARRVAL,$2,$2,$2);
                                    else if(ptr->type==strarrtype) $$=makeNode(0,strtype,ptr,NULL,tARRVAL,$2,$2,$2);
                                }
        ;
ArgList : ArgList',' Expr   {   // argument list will be linked with center pointer
                                $1->center=$3;
                                $$=$1;
                            }
        | Expr              {$$=$1;}
        ;

%%

int main(){
    FILE *fp=fopen("input.ac","r");
    yyin=fp;
    SP=4096;
    yyparse();
    Gsymbol* ptr=Ghead;
    if(!ptr) printf("What\n");
    for(;ptr;ptr=ptr->next)printf("%s ",ptr->name);
    printf("parsing complete\n");

    outFile=fopen("a.xsm","w");
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
    genErrorHandler();
    genExit();
    return 0;
}

//fsymbol

void yyerror(char* s){
    printf("%s\n",s);
    exit(0);
}

void functionPreperation(Gsymbol *funct){
    fprintf(outFile,"F%d:\n",funct->flabel);
    fprintf(outFile,"PUSH BP\n");
    fprintf(outFile,"MOV BP, SP\n");
    Lsymbol* lvar=funct->fsymbols;
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
    fprintf(outFile,"MAIN:\n");
    fprintf(outFile,"CALL F0!\n");
    fprintf(outFile,"JMP EXITCODE!\n");
}

bool isArithmetic(node* left, node* right){
    if(left==NULL || right==NULL){
        yyerror("syntax error");
        exit(0);
    }
    if(left->type!= inttype || right->type!=inttype){
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
    if(left->type!= booltype || right->type!=booltype){
        yyerror("type mismatch");
        exit(0);
    }
    return true;
}

