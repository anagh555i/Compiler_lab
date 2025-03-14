%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    // #include "lex.yy.h"

    extern FILE *yyin;
    extern void yyerror(char* s);
    extern int yylex();

    #define inttype 0
    #define booltype 1

    typedef struct node{
        int val;    //leaf node val
        int type;   // type of variable inttype or booltype
        char *varname;  // name of variable
        int nodeType; // leaf node info read/write/+/*/...
        struct node* left;
        struct node* right;
        struct node* center; // for storing if and while condition
    }node;

    int variables[26];
    int evalCB=0;
    node* root;

    node* makeNode(int val,int type,char varname,int nodeType,node* left,node* right,node* center);
    #define tCONNECT 0 //connector
    #define tCONST 1 //constant value
    #define tVAR 2 //variable
    #define tREAD 3   //read
    #define tWRITE 4 //write
    #define tADD 5 // +
    #define tSUB 6 // - 
    #define tMUL 7 // *
    #define tDIV 8 // /
    #define tASSIGN 9 // =
    #define tLT 10 // <
    #define tGT 11 // >
    #define tLE 12 // <=
    #define tGE 13 // >=
    #define tEQ 14 // ==
    #define tNEQ 15 // !=
    #define tAND 16 // AND
    #define tOR 17 // OR
    #define tIF 18 // IF node
    #define tWHILE 19 // WHILE node
    #define tDOWHILE 20 //DO WHILE node
    #define tREPEATUNTIL 21 //DO WHILE node
    #define tBREAK 22 // break
    #define tCONTINUE 23 // continue
    //makeNode(val,type,varname,nodeType,left,right,center);

    FILE* outFile;
    int currReg;

    int genCode(node* root);
    void genVarSpaceCode();
    void genHeader();
    int getReg();
    void freeReg();
    void handleWrite(int Wreg);
    void handleRead(node* root);
    int handleArithmetic(node* root);
    void handleAssignment(node* root);
    void genExit();
    void handleIfElse(node* root);
    int handleComparison(node* root);
    void handleWhile(node* root);
    void handleDoWhile(node* root);
    void handleRepeatUntil(node* root);

    bool isArithmetic(node* left, node* right);
    bool isBoolean(node* left, node* right);

    void printTree(node* root);
    int evaluator(node* root);

    int space=0;
    const int varBase=4096;
    int label=0;
    int WHILELABELS[]={-1,-1};
%}

%start Program
%union{
    int Int;
    char Char;
    struct node* nodePtr;
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

%token <Int> NUM
%token <Char> ID 


%type <nodePtr> Expr
%type <nodePtr> Slist
%type <nodePtr> Stmt
%type <nodePtr> InputStmt
%type <nodePtr> OutputStmt
%type <nodePtr> AssgStmt
%type <nodePtr> Ifstmt
%type <nodePtr> LoopStmt

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

Program :   begin Slist end         {root=$2;}
        |   begin end               {root=NULL;}
        ;
Slist   :   Slist Stmt              {$$=makeNode(0,0,' ',tCONNECT,$1,$2,NULL);}
        |   Stmt                    {$$=$1;}
        ;
Stmt    :   InputStmt ';'           {$$=$1;}
        |   OutputStmt ';'          {$$=$1;}
        |   AssgStmt ';'            {$$=$1;}
        |   Ifstmt ';'              {$$=$1;}
        |   LoopStmt ';'           {$$=$1;}
        |   BREAK ';'               {$$=makeNode(0,0,' ',tBREAK,NULL,NULL,NULL);}
        |   CONTINUE ';'            {$$=makeNode(0,0,' ',tCONTINUE,NULL,NULL,NULL);}
        ;
LoopStmt    :   WHILE '(' Expr ')' DO Slist ENDWHILE    {if(isBoolean($3,$3)) $$=makeNode(0,0,' ',tWHILE,$6,$6,$3);}
            |   DO Slist WHILE '(' Expr ')'             {if(isBoolean($5,$5)) $$=makeNode(0,0,' ',tDOWHILE,$2,$2,$5);}
            |   REPEAT Slist UNTIL '(' Expr ')'             {if(isBoolean($5,$5)) $$=makeNode(0,0,' ',tREPEATUNTIL,$2,$2,$5);}
            ;
Ifstmt  :   IF '('Expr')' then Slist Else Slist ENDIF   {if(isBoolean($3,$3)) $$=makeNode(0,0,' ',tIF,$6,$8,$3);}
        |   IF '('Expr')' then Slist ENDIF              {if(isBoolean($3,$3)) $$=makeNode(0,0,' ',tIF,$6,NULL,$3);}
        ;/* ;   center->condition, left->iftrue, right-> else */
InputStmt   :   READ '(' ID ')'     {
                                    node* temp=makeNode(0,0,$3,tVAR,NULL,NULL,NULL);
                                    $$=makeNode(0,0,' ',tREAD,temp,temp,NULL);
                                    }
            ;
OutputStmt  :   WRITE '(' Expr ')'  {$$=makeNode(0,0,' ',tWRITE,$3,$3,NULL);}
            ;
AssgStmt    :   ID '=' Expr         {
                                    node* temp=makeNode(0,0,$1,tVAR,NULL,NULL,NULL);
                                    $$=makeNode(0,0,' ',tASSIGN,temp,$3,NULL);
                                    }
            ;
Expr    :   Expr '+' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,' ',tADD,$1,$3,NULL);}
        |   Expr '-' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,' ',tSUB,$1,$3,NULL);}
        |   Expr '*' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,' ',tMUL,$1,$3,NULL);}
        |   Expr '/' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,0,' ',tDIV,$1,$3,NULL);}
        |   Expr '>' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,1,' ',tGT,$1,$3,NULL);} 
        |   Expr '<' Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,1,' ',tLT,$1,$3,NULL);} 
        |   Expr GE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,1,' ',tGE,$1,$3,NULL);} 
        |   Expr LE Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,1,' ',tLE,$1,$3,NULL);} 
        |   Expr EQ Expr            {if(isArithmetic($1,$3)) $$=makeNode(0,1,' ',tEQ,$1,$3,NULL);} 
        |   Expr NEQ Expr           {if(isArithmetic($1,$3)) $$=makeNode(0,1,' ',tNEQ,$1,$3,NULL);} 
        |   Expr AND Expr           {if(isBoolean($1,$3)) $$=makeNode(0,1,' ',tAND,$1,$3,NULL);} 
        |   Expr OR Expr            {if(isBoolean($1,$3)) $$=makeNode(0,1,' ',tOR,$1,$3,NULL);} 
        |   '(' Expr ')'            {$$=$2;}
        |   NUM                     {$$=makeNode($1,0,' ',tCONST,NULL,NULL,NULL);}
        |   ID                      {$$=makeNode(0,0,$1,tVAR,NULL,NULL,NULL);}
        ;

%%

int main(){
    FILE *fp=fopen("input2.txt","r");
    yyin=fp;
    yyparse();

    /* for(int i=0;i<26;i++) variables[i]=0;
    evaluator(root);
    return 0; */

    outFile=fopen("a.xsm","w");
    printTree(root);
    currReg=0;

    genHeader();
    genVarSpaceCode();
    int reg=genCode(root);
    genExit();
}

void handleDoWhile(node* root){
    if(root==NULL || root->nodeType!=tDOWHILE) return;
    int L1=label++;
    int L2=label++;
    WHILELABELS[0]=L1; // for continue;
    WHILELABELS[1]=L2; // for break;
    genCode(root->left); // making sure it runs once, then the while loop itself
    fprintf(outFile,"L%d:\n",L1); 
    int reg=genCode(root->center);
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L2);
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    WHILELABELS[0]=-1;
    WHILELABELS[1]=-1;
    freeReg();
}
void handleRepeatUntil(node* root){
    if(root==NULL || root->nodeType!=tREPEATUNTIL) return;
    int L1=label++;
    int L2=label++;
    WHILELABELS[0]=L1; // for continue;
    WHILELABELS[1]=L2; // for break;
    genCode(root->left); // making sure it runs once, then the while loop itself
    fprintf(outFile,"L%d:\n",L1); 
    int reg=genCode(root->center);
    fprintf(outFile,"JNZ R%d, L%d!\n",reg,L2); // jump if non zero
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    WHILELABELS[0]=-1;
    WHILELABELS[1]=-1;
    freeReg();
}
void handleWhile(node* root){
    if(root==NULL || root->nodeType!=tWHILE) return;
    int L1=label++;
    fprintf(outFile,"L%d:\n",L1); 
    int L2=label++;
    WHILELABELS[0]=L1; // for continue;
    WHILELABELS[1]=L2; // for break;
    int reg=genCode(root->center);
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L2);
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    WHILELABELS[0]=-1;
    WHILELABELS[1]=-1;
    freeReg();
}

int handleComparison(node* root){
    if(root==NULL) return 100;
    int r1=genCode(root->left);
    int r2=genCode(root->right);
    switch(root->nodeType){
        case tLT:
            fprintf(outFile,"LT R%d, R%d\n",r1,r2);
        break;
        case tGT:
            fprintf(outFile,"GT R%d, R%d\n",r1,r2);
        break;
        case tEQ:
            fprintf(outFile,"EQ R%d, R%d\n",r1,r2);
        break;
        case tNEQ:
            fprintf(outFile,"NE R%d, R%d\n",r1,r2);
        break;
        case tGE:
            fprintf(outFile,"GE R%d, R%d\n",r1,r2);
        break;
        case tLE:
            fprintf(outFile,"LE R%d, R%d\n",r1,r2);
        break;
    }
    freeReg();
    return r1;

}

void handleIfElse(node* root){
    if(root==NULL || root->nodeType!=tIF) return;
    int reg=genCode(root->center); // value of if else condition stored in reg
    int L1=label++;
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L1);
    genCode(root->left);
    if(root->right){
        int L2=label++;
        fprintf(outFile,"JMP L%d!\n",L2);
        fprintf(outFile,"L%d:\n",L1);
        genCode(root->right);
        fprintf(outFile,"L%d:\n",L2);
    }
    else fprintf(outFile,"L%d:\n",L1);
    freeReg();
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

int evaluator(node* root){
    if(root==NULL || evalCB==tBREAK || evalCB==tCONTINUE) return 0;
    int i,j;
    bool cond;
    switch(root->nodeType){
        case tCONNECT: //connector
            evaluator(root->left);
            evaluator(root->right);
        break;
        case tCONST: //constants
            return root->val;
        break;
        case tVAR: //Variable
            return variables[*(root->varname)-'a'];
        break;
        case tREAD: //Read
        printf("read\n");
            i=*(root->left->varname) - 'a';
            scanf("%d",&variables[i]);
            return 100;//junk value
        break;
        case tWRITE: //Write
        printf("write\n");
            i=evaluator(root->left);
            printf("%d\n",i);
        break;
        case tASSIGN: //=
        printf("=\n");
            i=*(root->left->varname) - 'a';
            variables[i]=evaluator(root->right);
            return 100;// junk
        break;
        case 5: //+
        printf("+\n");
            return evaluator(root->left) + evaluator(root->right);
        break;
        case 6: //-
        printf("-\n");
            return evaluator(root->left) - evaluator(root->right);
        break;
        case 7: //*
        printf("*\n");
            return evaluator(root->left) * evaluator(root->right);
        break;
        case 8: // /
        printf("/\n");
            return evaluator(root->left) / evaluator(root->right);
        break;
        case tLT:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i<j) return 1;
            return 0;
        break;
        case tGT:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i>j) return 1;
            return 0;
        break;
        case tEQ:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i==j) return 1;
            return 0;
        break;
        case tNEQ:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i!=j) return 1;
            return 0;
        break;
        case tGE:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i>=j) return 1;
            return 0;
        break;
        case tLE:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i<=j) return 1;
            return 0;
        break;
        case tIF:
            cond=evaluator(root->center);
            if(cond) evaluator(root->left);
            else evaluator(root->right);
        break;
        case tWHILE:
            while(evaluator(root->center)){
                evaluator(root->left);
                if(evalCB==tBREAK){
                    evalCB=0;
                    break;
                }
                evalCB=0;
            }
        break;
        case tDOWHILE:
            evaluator(root->left);
            if(evalCB==tBREAK){
                evalCB=0;
                return 0;
            }
            evalCB=0;
            while(evaluator(root->center)){
                evaluator(root->left);
                if(evalCB==tBREAK){
                    evalCB=0;
                    break;
                }
                evalCB=0;
            }
        break;
        case tREPEATUNTIL:
            evaluator(root->left);
            if(evalCB==tBREAK){
                evalCB=0;
                return 0;
            }
            evalCB=0;
            while(!evaluator(root->center)){
                evaluator(root->left);
                if(evalCB==tBREAK){
                    evalCB=0;
                    break;
                }
                evalCB=0;
            }
        break;
        case tBREAK:
            evalCB=tBREAK;
            return 0;
        break;
        case tCONTINUE:
            evalCB=tCONTINUE;
            return 0;
        break;
    }
    return 100;// junk
}
int genCode(node* root){
    int reg;
    switch(root->nodeType){
        case tCONNECT: //connector
            genCode(root->left);
            genCode(root->right);
        break;
        case tCONST: //constants
            reg=getReg();
            fprintf(outFile,"MOV R%d, %d\n",reg,root->val);
            return reg;
        break;
        case tVAR: //Variable
            reg=getReg();
            fprintf(outFile,"MOV R%d, [%d]\n",reg,varBase+(root->varname)[0]-'a');
            return reg;
        break;
        case tREAD: //Read
            handleRead(root);
        break;
        case tWRITE: //Write
            reg=genCode(root->left);
            handleWrite(reg);
            freeReg();
        break;
        case tASSIGN: //=
            handleAssignment(root);
        break;
        case tIF:
            handleIfElse(root);
        break;
        case tWHILE:
            handleWhile(root);
        break;
        case tDOWHILE:
            handleDoWhile(root);
        break;
        case tREPEATUNTIL:
            handleRepeatUntil(root);
        break;
        case tBREAK:
            if(WHILELABELS[1]!=-1) fprintf(outFile,"JMP L%d!\n",WHILELABELS[1]);
            else {
                yyerror("break outside looping statement\n");
                exit(0);
            }
        break;
        case tCONTINUE:
            if(WHILELABELS[0]!=-1) fprintf(outFile,"JMP L%d!\n",WHILELABELS[0]);
            else{
                yyerror("continue outside looping statement\n");
                exit(0);
            }
        break;
    }
    if(root->nodeType>4 && root->nodeType<9){ //+-*/
        return handleArithmetic(root);
    }
    else if(root->nodeType>9 && root->nodeType<16){
        return handleComparison(root);
    }
    return 100;// junk
}
void handleAssignment(node* root){
    char c=*(root->left->varname);
    int reg=genCode(root->right);
    fprintf(outFile,"MOV [%d], R%d\n",varBase+c-'a',reg);
    freeReg();
}
int handleArithmetic(node* root){
    int left=genCode(root->left);
    int right=genCode(root->right);
    char* op;
    switch(root->nodeType){
        case 5:
            op="ADD";
            break;
        case 6:
            op="SUB";
            break;
        case 7:
            op="MUL";
            break;
        case 8:
            op="DIV";
            break;
    }
    fprintf(outFile,"%s R%d, R%d\n",op,left,right);
    freeReg();
    return left;
}
void handleWrite(int Wreg){
    int reg=getReg();

    fprintf(outFile,"MOV R%d, \"Write\"\n",reg); //funct code
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, -2\n",reg); //arg 1=-2 for write
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"PUSH R%d\n",Wreg); //arg2 data to be printed is in wReg

    fprintf(outFile,"PUSH R%d\n",reg);  //arg 3
    fprintf(outFile,"PUSH R%d\n",reg);  // space for return value

    fprintf(outFile,"CALL 0\n");

    fprintf(outFile,"POP R%d\n",reg);   // return value CAN BE USED LATER FOR ERROR DETECTION
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    freeReg();
}
void genVarSpaceCode(){
    fprintf(outFile,"MOV SP,4122\n"); //allocate space for 26 variables;
    //static allocation in stack itself
}
void genHeader(){
    fprintf(outFile,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
}
int getReg(){
    return currReg++;
}
void freeReg(){
    if(currReg>0) currReg--;
}
void handleRead(node* root){
    char c=*(root->left->varname);
    int reg=getReg();

    fprintf(outFile,"MOV R%d, \"Read\"\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, -1\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, %d\n",reg,varBase+c-'a');
    fprintf(outFile,"PUSH R%d\n",reg);
    
    fprintf(outFile,"PUSH R%d\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"CALL 0\n");
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    freeReg();
}
void genExit(){
    fprintf(outFile,"MOV R0, \"Exit\"\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"CALL 0");
}

node* makeNode(int val,int type,char varname,int nodeType,node* left,node* right,node* center){
    node* ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->val=val;
    ptr->type=type;

    char * temp=(char*)malloc(sizeof(char)*2);
    temp[0]=varname;
    temp[1]='\0';
    ptr->varname=temp;

    ptr->nodeType=nodeType;
    ptr->left=left;
    ptr->right=right;
    ptr->center=center;
    return ptr;
}

void yyerror(char* s){
    printf("%s\n",s);
}

void printTree(node* root){
    if(root==NULL) return;
    for(int i=0;i<space;i++)printf("|");
    int temp=root->nodeType;
    space+=3;
    if(temp==0) printf("->$\n");
    else if(temp==1) printf("->%d\n",root->val);
    else if(temp==2) printf("->%s\n",root->varname);
    else if(temp==3) printf("->R\n");
    else if(temp==4) printf("->W\n");
    else if(temp==5) printf("->+\n");
    else if(temp==6) printf("->-\n");
    else if(temp==7) printf("->*\n");
    else if(temp==8) printf("->/\n");
    else if(temp==9) printf("->=\n");
    else if(temp==10) printf("->LT\n");
    else if(temp==11) printf("->GT\n");
    else if(temp==12) printf("->LE\n");
    else if(temp==13) printf("->GE\n");
    else if(temp==14) printf("->EQ\n");
    else if(temp==15) printf("->NEQ\n");
    else if(temp==16) printf("->AND\n");
    else if(temp==17) printf("->OR\n");
    else if(temp==18) {
        printf("->IF\n");
        printTree(root->center);
    }
    else if(temp==19){
        printf("->WHILE\n");
        printTree(root->center);
    }
    printTree(root->left);
    printTree(root->right);
    space-=3;
}