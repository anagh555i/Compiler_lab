%{
    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node{
        int val;    //leaf node val
        int type;   // type of variable
        char *varname;  // name of variable
        int nodeType; // leaf node info read/write/+/*/...
        struct node* left;
        struct node* right;
    }node;

    node* root;

    node* makeNode(int val,int type,char varname,int nodeType,node* left,node* right);
    //makeNode(val,type,varname,nodeType,left,right);
    /*  NODE TYPES  
        0 -> connector
        1 -> const
        2 -> var
        3 -> read
        4 -> write
        5 -> +
        6 -> -
        7 -> *
        8 -> /
        9 -> =
    */

    FILE* outFile;
    int currReg;
    const int varBase=4096;

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

    int space=0;
    void printTree(node* root);
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

%token <Int> NUM
%token <Char> ID 


%type <nodePtr> Expr
%type <nodePtr> Slist
%type <nodePtr> Stmt
%type <nodePtr> InputStmt
%type <nodePtr> OutputStmt
%type <nodePtr> AssgStmt

%left '+'
%left '-'
%left '*'
%left '/' 

%%

Program :   begin Slist end         {root=$2;}
        |   begin end               {root=NULL;}
        ;
Slist   :   Slist Stmt              {$$=makeNode(0,0,' ',0,$1,$2);}
        |   Stmt                    {$$=$1;}
        ;
Stmt    :   InputStmt ';'           {$$=$1;}
        |   OutputStmt ';'          {$$=$1;}
        |   AssgStmt ';'            {$$=$1;}
        ;
InputStmt   :   READ '(' ID ')'     {
                                    node* temp=makeNode(0,0,$3,2,NULL,NULL);
                                    $$=makeNode(0,0,' ',3,temp,temp);
                                    }
            ;
OutputStmt  :   WRITE '(' Expr ')'  {$$=makeNode(0,0,' ',4,$3,$3);}
            ;
AssgStmt    :   ID '=' Expr         {
                                    node* temp=makeNode(0,0,$1,2,NULL,NULL);
                                    $$=makeNode(0,0,' ',9,temp,$3);
                                    }
            ;
Expr    :   Expr '+' Expr           {$$=makeNode(0,0,' ',5,$1,$3);}
        |   Expr '-' Expr           {$$=makeNode(0,0,' ',6,$1,$3);}
        |   Expr '*' Expr           {$$=makeNode(0,0,' ',7,$1,$3);}
        |   Expr '/' Expr           {$$=makeNode(0,0,' ',8,$1,$3);}
        |   '(' Expr ')'            {$$=$2;}
        |   NUM                     {$$=makeNode($1,0,' ',1,NULL,NULL);}
        |   ID                      {
                                    $$=makeNode(0,0,$1,2,NULL,NULL);
                                    }
        ;

%%

int main(){
    yyparse();
    outFile=fopen("a.xsm","w");
    printTree(root);
    currReg=0;

    genHeader();
    genVarSpaceCode();
    int reg=genCode(root);
    genExit();
}

int genCode(node* root){
    int reg;
    switch(root->nodeType){
        case 0: //connector
            genCode(root->left);
            genCode(root->right);
            return 100; // junk
        break;
        case 1: //constants
            reg=getReg();
            fprintf(outFile,"MOV R%d, %d\n",reg,root->val);
            return reg;
        break;
        case 2: //Variable
            reg=getReg();
            fprintf(outFile,"MOV R%d, [%d]\n",reg,varBase+(root->varname)[0]-'a');
            return reg;
        break;
        case 3: //Read
            handleRead(root);
            return 100;//junk value
        break;
        case 4: //Write
            reg=genCode(root->left);
            handleWrite(reg);
            freeReg();
        break;
        case 9: //=
            handleAssignment(root);
            return 100;// junk
        break;
        default: //+-*/
            return handleArithmetic(root);
        break;
    }
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
    fprintf(outFile,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n\n");
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
    fprintf(outFile,"PUSH R%d",reg);

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

node* makeNode(int val,int type,char varname,int nodeType,node* left,node* right){
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
    return ptr;
}

yyerror(char* s){
    printf("%s\n",s);
}

void printTree(node* root){
    if(root==NULL) return;
    for(int i=0;i<space;i++)printf("|");
    int temp=root->nodeType;
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
    space+=3;
    printTree(root->left);
    printTree(root->right);
    space-=3;
}