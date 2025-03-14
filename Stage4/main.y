%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<string.h>
    #include "tree.h"
    #include "parser.h"

    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol tabel head
    //makeNode(val,type,varname,nodeType,left,right,center);

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int WHILELABELS[]={-1,-1};
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
%token then 
%token Else 
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE 
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

%%

sourceCode      :       Delcarations Program    {root=makeNode(0,0,NULL,tCONNECT,$1,$2,NULL);}
                ;

Delcarations    :       DECL DecList ENDDECL    {$$=NULL;}
                |       DECL ENDDECL            {$$=NULL;}
                ;
DecList         :       DecList Decl            {$$=NULL;}
                |       Decl                    {$$=NULL;}
                ;
Decl            :       INT VarList ';'         {
                                                  $$=NULL;
                                                  Lnode* ptr1=$2;
                                                  for(;ptr1;ptr1=ptr1->next){
                                                        if(lookUp(ptr1->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                        }
                                                        install(ptr1->s,ptr1->num?tdINTPTR:tdINT,1,SP++);
                                                  }
                                                  Gsymbol* ptr=Ghead;
                                                }
                |       STR VarList ';'         {
                                                  $$=NULL;
                                                  Lnode* ptr1=$2;
                                                  for(;ptr1;ptr1=ptr1->next){
                                                        if(lookUp(ptr1->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                        }
                                                        install(ptr1->s,ptr1->num?tdSTRPTR:tdSTR,1,SP++);
                                                  }
                                                }
                ; 
VarList         :       VarList ',' ID          {$$=makeLnode($3,0,$1);}
                |       VarList ',' '*'ID       {$$=makeLnode($4,1,$1);} // list num=1 for pointers
                |       ID                      {$$=makeLnode($1,0,NULL);}
                |       '*'ID                   {$$=makeLnode($2,1,NULL);} //list num=1 for pointers;
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
        |   Ifstmt ';'              {$$=$1;}
        |   LoopStmt ';'            {$$=$1;}
        |   BREAK ';'               {$$=makeNode(0,0,NULL,tBREAK,NULL,NULL,NULL);}
        |   CONTINUE ';'            {$$=makeNode(0,0,NULL,tCONTINUE,NULL,NULL,NULL);}
        ;
LoopStmt    :   WHILE '(' Expr ')' DO Slist ENDWHILE    {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,tWHILE,$6,$6,$3);}
            |   DO Slist WHILE '(' Expr ')'             {if(isBoolean($5,$5)) $$=makeNode(0,0,NULL,tDOWHILE,$2,$2,$5);}
            |   REPEAT Slist UNTIL '(' Expr ')'             {if(isBoolean($5,$5)) $$=makeNode(0,0,NULL,tREPEATUNTIL,$2,$2,$5);}
            ;
Ifstmt  :   IF '('Expr')' then Slist Else Slist ENDIF   {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,tIF,$6,$8,$3);}
        |   IF '('Expr')' then Slist ENDIF              {if(isBoolean($3,$3)) $$=makeNode(0,0,NULL,tIF,$6,NULL,$3);}
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
                                    if(ptr) temp=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    if((ptr->type==tdINT || ptr->type==tdSTR) && $3->type==Addresstype) yyerror("Assignment of Pointer type to variable error");
                                    if((ptr->type==tdINTPTR || ptr->type==tdSTRPTR) && $3->type!=Addresstype) yyerror("Assignment expected address type");
                                    $$=makeNode(0,0,NULL,tASSIGN,temp,$3,NULL);
                                    }
            |   '*'ID '=' Expr      {
                                    Gsymbol* ptr=lookUp($2);
                                    node* temp=NULL;
                                    printf("%s\n",ptr->name);
                                    if(ptr) temp=makeNode(0,0,ptr,tPTR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    $$=makeNode(0,0,NULL,tASSIGN,temp,$4,NULL);
                                    }
            ;
Expr    :   Expr '+' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,NULL,tADD,$1,$3,NULL);}
        |   Expr '-' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,NULL,tSUB,$1,$3,NULL);}
        |   Expr '*' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,NULL,tMUL,$1,$3,NULL);}
        |   Expr '/' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,NULL,tDIV,$1,$3,NULL);}
        |   Expr '>' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,1,NULL,tGT,$1,$3,NULL);} 
        |   Expr '<' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,1,NULL,tLT,$1,$3,NULL);} 
        |   Expr GE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,1,NULL,tGE,$1,$3,NULL);} 
        |   Expr LE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,1,NULL,tLE,$1,$3,NULL);} 
        |   Expr EQ Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,1,NULL,tEQ,$1,$3,NULL);} 
        |   Expr NEQ Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,1,NULL,tNEQ,$1,$3,NULL);} 
        |   Expr AND Expr           {if(isBoolean($1,$3)) $$=makeNode(0,1,NULL,tAND,$1,$3,NULL);} 
        |   Expr OR Expr            {if(isBoolean($1,$3)) $$=makeNode(0,1,NULL,tOR,$1,$3,NULL);} 
        |   '(' Expr ')'            {$$=$2;}
        |   NUM                     {$$=makeNode($1,0,NULL,tCONST,NULL,NULL,NULL);}
        |   ID                      {
                                    printf("From expr %s\n",$1);
                                    Gsymbol* ptr=lookUp($1);
                                    if(ptr)$$=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    }
        |  '&' ID                   {
                                    Gsymbol* ptr=lookUp($2);
                                    if(ptr) $$=makeNode(0,Addresstype,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");  
                                    } // don't take constant, lets take tvar itself so that we can check in handleAssignment
        |  '*' ID                   {
                                    Gsymbol* ptr=lookUp($2);
                                    if(ptr) $$=makeNode(0,0,ptr,tPTR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");  
                                    }
        ;

%%

int main(){
    FILE *fp=fopen("input2.txt","r");
    yyin=fp;
    SP=4096;
    yyparse();
    printf("parsing complete\n");
    outFile=fopen("a.xsm","w");
    space=0;
    printTree(root);
    currReg=0;

    genHeader();
    genVarSpaceCode(); // being used for setting stack pointer to 4096;
    int reg=genCode(root);
    genExit();
}

void yyerror(char* s){
    printf("%s\n",s);
    exit(0);
}