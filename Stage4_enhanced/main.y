%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<string.h>
    #include "tree.h"
    #include "codeGen.h"

    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    //makeNode(val,type,varname,nodeType,left,right,center);

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int WHILELABELS[]={-1,-1};// new list based while labels storage required
    Lnode* breakLabels=NULL;
    Lnode* continueLabels=NULL;
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
%token DECL
%token ENDDECL 

%token <Int> NUM
%token <String> ID
%token <String> LITERAL 

%type <nodePtr> Expr
%type <nodePtr> Slist
%type <nodePtr> Stmt
%type <nodePtr> InputStmt
%type <nodePtr> OutputStmt
%type <nodePtr> AssgStmt
%type <nodePtr> Ifstmt
%type <nodePtr> LoopStmt
%type <nodePtr> Program
%type <nodePtr> Delcarations

%type <listPtr> VarList
%type <nodePtr> Decl
%type <nodePtr> DecList
%type <listPtr> ArrList
%type <nodePtr> Array

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

sourceCode      :       Delcarations Program    {root=$2;}
                ;

Delcarations    :       DECL DecList ENDDECL    {}
                |       DECL ENDDECL            {}
                ;
DecList         :       DecList Decl            {}
                |       Decl                    {}
                ;
Decl            :       INT VarList ';'         {
                                                  Lnode* ptr=$2;
                                                  for(;ptr;ptr=ptr->next){
                                                        if(lookUp(ptr->s)){
                                                            yyerror("Variable already Declared");
                                                            exit(0);
                                                        }
                                                        if(ptr->num==valtype) install(ptr->s,inttype,1,SP++);
                                                        else install(ptr->s,intptrtype,1,SP++);
                                                        // install(char* name,int type, int size,int binding);
                                                  }
                                                }
                |       STR VarList ';'         {
                                                  Lnode* ptr=$2;
                                                  for(;ptr;ptr=ptr->next){
                                                        if(lookUp(ptr->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                        }
                                                        if(ptr->num==valtype) install(ptr->s,strtype,1,SP++);
                                                        else install(ptr->s,strptrtype,1,SP++);
                                                  }
                                                }
                |       INT ID ArrList';'       {
                                                    if(lookUp($2)) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=1;
                                                    Lnode* ptr=$3;
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    install($2,intarrtype,size,SP);
                                                    SP+=size;
                                                    Gsymbol* g=lookUp($2);
                                                    g->dim=makeLnode("",dim,$3);
                                                }
                |       STR ID ArrList';'       {
                                                    if(lookUp($2)) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=1;
                                                    Lnode* ptr=$3;
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    install($2,strarrtype,size,SP);
                                                    SP+=size;
                                                    Gsymbol* g=lookUp($2);
                                                    g->dim=makeLnode("",dim,$3);
                                                }
                ; 
ArrList         :       '[' NUM ']' ArrList     {$$=makeLnode("",$2,$4);} // returns linear chain of dimension
                |       '[' NUM ']'             {$$=makeLnode("",$2,NULL);}
                ;
VarList         :       VarList ',' ID          {$$=makeLnode($3,valtype,$1);}
                |       VarList ',' '*'ID       {$$=makeLnode($4,ptrtype,$1);} // list num stores type of variable
                |       ID                      {$$=makeLnode($1,valtype,NULL);}
                |       '*'ID                   {$$=makeLnode($2,ptrtype,NULL);} 
                ;



Program :   begin Slist end         {$$=$2;}
        |   begin end               {$$=NULL;}
        ;
Slist   :   Slist Stmt              {$$=makeNode(0,0,NULL,tCONNECT,$1,$2,NULL);}
        |   Stmt                    {$$=$1;}
        ;
Stmt    :   InputStmt ';'           {$$=$1;}
        |   OutputStmt ';'          {$$=$1;}
        |   AssgStmt ';'            {$$=$1;}
        |   Ifstmt              {$$=$1;}
        |   LoopStmt            {$$=$1;}
        |   BREAK ';'               {$$=makeNode(0,0,NULL,tBREAK,NULL,NULL,NULL);}
        |   CONTINUE ';'            {$$=makeNode(0,0,NULL,tCONTINUE,NULL,NULL,NULL);}
        ;
LoopStmt    :   WHILE '(' Expr ')' '{' Slist '}'    {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,tWHILE,$6,$6,$3);}
            |   DO '{' Slist '}' WHILE '(' Expr ')'             {if(isBoolean($7,$7)) $$=makeNode(0,0,NULL,tDOWHILE,$3,$3,$7);}
            |   REPEAT '{' Slist '}' UNTIL '(' Expr ')'             {if(isBoolean($7,$7)) $$=makeNode(0,0,NULL,tREPEATUNTIL,$3,$3,$7);}
            ;
Ifstmt  :   IF '('Expr')' '{' Slist '}' Else '{' Slist '}'   {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,tIF,$6,$10,$3);}
        |   IF '('Expr')' '{' Slist '}'             {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,tIF,$6,NULL,$3);}
        ;/* ;   center->condition, left->iftrue, right-> else */
InputStmt   :   READ '(' ID ')'     {
                                    Gsymbol* ptr=lookUp($3);
                                    node* temp=NULL;
                                    if(ptr) temp=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    $$=makeNode(0,0,NULL,tREAD,temp,temp,NULL);
                                    }
            ;
OutputStmt  :   WRITE '(' Expr ')'  {$$=makeNode(0,0,NULL,tWRITE,$3,$3,NULL);}
            ;
AssgStmt    :   ID '=' Expr         {
                                    Gsymbol* ptr=lookUp($1);
                                    node* temp=NULL;
                                    if(ptr) temp=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    $$=makeNode(0,0,NULL,tASSIGN,temp,$3,NULL);
                                    }
            |   '*'ID '=' Expr      {
                                    Gsymbol* ptr=lookUp($2);
                                    node* var=NULL;
                                    if(ptr) var=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");
                                    if(ptr->type==intptrtype)var=makeNode(0,inttype,NULL,tVALUEAT,var,var,var);
                                    else if(ptr->type==strptrtype) var=makeNode(0,strtype,NULL,tVALUEAT,var,var,var);
                                    else yyerror("type mismatch");
                                    $$=makeNode(0,0,NULL,tASSIGN,var,$4,NULL);
                                    }
            |   ID Array '=' Expr {
                                        Gsymbol* ptr=lookUp($1);
                                        if(!ptr) yyerror("variable undeclared");
                                        node* var=NULL;
                                        if(ptr->type==intarrtype) var=makeNode(0,inttype,ptr,tARRVAL,$2,$2,$2);
                                        else if(ptr->type==strarrtype) var=makeNode(0,strtype,ptr,tARRVAL,$2,$2,$2);
                                        if(var->type!=$4->type) yyerror("type mismatch");
                                        $$=makeNode(0,inttype,NULL,tASSIGN,var,$4,$4);
                                    }
            ;
Array   :       '[' Expr ']' Array     {if(isArithmetic($2,$2)){
                                            $2->left=$4;
                                            $$=$2;
                                        }
                                      } 
        |       '[' Expr ']'           {if(isArithmetic($2,$2)) $$=$2;}
        ;
Expr    :   Expr '+' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,tADD,$1,$3,NULL);}
        |   Expr '-' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,tSUB,$1,$3,NULL);}
        |   Expr '*' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,tMUL,$1,$3,NULL);}
        |   Expr '/' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,tDIV,$1,$3,NULL);}
        |   Expr '%' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,inttype,NULL,tMOD,$1,$3,NULL);}
        |   Expr '>' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,tGT,$1,$3,NULL);} 
        |   Expr '<' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,tLT,$1,$3,NULL);} 
        |   Expr GE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,tGE,$1,$3,NULL);} 
        |   Expr LE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,tLE,$1,$3,NULL);} 
        |   Expr EQ Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,tEQ,$1,$3,NULL);} 
        |   Expr NEQ Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,booltype,NULL,tNEQ,$1,$3,NULL);} 
        |   Expr AND Expr           {if(isBoolean($1,$3)) $$=makeNode(0,booltype,NULL,tAND,$1,$3,NULL);} 
        |   Expr OR Expr            {if(isBoolean($1,$3)) $$=makeNode(0,booltype,NULL,tOR,$1,$3,NULL);} 
        |   '(' Expr ')'            {$$=$2;}
        |   NUM                     {$$=makeNode($1,inttype,NULL,tCONST,NULL,NULL,NULL);}
        |   LITERAL                 {
                                     printf("STARTED parsing literal");
                                     $$=makeNode(0,strtype,NULL,tLITERAL,NULL,NULL,NULL);
                                     $$->literal=$1;
                                     printf("FINISHED parsing literal");
                                    }
        |   ID                      {
                                    printf("From expr %s\n",$1);
                                    Gsymbol* ptr=lookUp($1);
                                    if(ptr)$$=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    }
        |  '&' ID                   {
                                    Gsymbol* ptr=lookUp($2);
                                    node* var=NULL;
                                    if(ptr) var=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable"); 
                                    $$=makeNode(0,inttype,NULL,tADDRESSOF,var,var,var) ; // i don't see the point of address type, now we can do &var+1 and all
                                    }
        |  '*' ID                   {
                                    Gsymbol* ptr=lookUp($2);
                                    node* var=NULL;
                                    if(ptr) var=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");
                                    if(ptr->type==intptrtype)$$=makeNode(0,inttype,NULL,tVALUEAT,var,var,var);
                                    else if(ptr->type==strptrtype) $$=makeNode(0,strtype,NULL,tVALUEAT,var,var,var);
                                    }
        |   ID Array              {
                                        Gsymbol* ptr=lookUp($1);
                                        if(!ptr) yyerror("variable undeclared");
                                        if(ptr->type==intarrtype) $$=makeNode(0,inttype,ptr,tARRVAL,$2,$2,$2);
                                        else if(ptr->type==strarrtype) $$=makeNode(0,strtype,ptr,tARRVAL,$2,$2,$2);
                                    }
        ;

%%

int main(){
    FILE *fp=fopen("bubblesort.ac","r");
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
    currReg=0;

    genHeader();
    genVarSpaceCode(); // set stack pointer to after declarations
    int reg=genCode(root);
    printf("codeGen completed\n");
    fprintf(outFile,"JMP EXITCODE!\n");
    genErrorHandler();
    genExit();
}

void yyerror(char* s){
    printf("%s\n",s);
    exit(0);
}