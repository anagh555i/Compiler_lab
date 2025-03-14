%{
    #include<stdio.h>
    #include<stdlib.h>

    typedef struct node{
        int val;
        char op;
        struct node* left;
        struct node* right;
    }node;
    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();
    FILE *outFile;

    node* root;
    node* makeLeafNode(int n);
    node* makeOperatorNode(char op,node* left,node* right);

    int currReg=0;
    int getReg();
    void freeReg();
    void genHeader();
    int genCode(node* root);
    void genWriteCode(int wReg);

    int space=0;
    void printTree(node* root);
%}

%union {
    int Int;
    struct node* Npointer;
    char Char;
}
%start S
%token <Int> NUM
%type <Npointer> Expr
%left '+'
%left '-'
%left '*'
%left '/'


%%

S   :   Expr    {root=$1;}
    ;

Expr    :  Expr '+' Expr    {$$=makeOperatorNode('+',$1,$3);}
        |  Expr '-' Expr    {$$=makeOperatorNode('-',$1,$3);}
        |  Expr '*' Expr    {$$=makeOperatorNode('*',$1,$3);}
        |  Expr '/' Expr    {$$=makeOperatorNode('/',$1,$3);}
        |  '('Expr')'       {$$=$2;}
        |  NUM              {$$=makeLeafNode($1);}
        ; 

%%

int main(){
    yyparse();
    outFile=fopen("a.xsm","w");
    genHeader();
    int reg=genCode(root);
    fprintf(outFile,"\n");
    genWriteCode(reg);
    printTree(root);
    /* printf("Run\n./xsm -l library.lib -e <Relative_path_to_xsm_file> --debug"); */
}

void genWriteCode(int Wreg){
    fprintf(outFile,"MOV SP, 4095\n");

    int reg=getReg();
    fprintf(outFile,"MOV R%d, \"Write\"\n",reg); //funct code
    fprintf(outFile,"PUSH R%d\n",reg);

    reg=getReg();
    fprintf(outFile,"MOV R%d, -2\n",reg); //arg 1=-2 for write
    fprintf(outFile,"PUSH R%d\n",reg);

    reg=getReg();
    fprintf(outFile,"PUSH R%d\n",Wreg); //arg2 data to be printed is in wReg

    fprintf(outFile,"PUSH R%d\n",reg);  //arg 3
    fprintf(outFile,"PUSH R%d\n",reg);  // space for return value

    fprintf(outFile,"CALL 0\n");

    fprintf(outFile,"POP R%d\n",reg);   // return value CAN BE USED LATER FOR ERROR DETECTION
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d",reg);
    freeReg();
    freeReg();
    freeReg();
}

int genCode(node* root){
    if(root->op==' '){
        int reg=getReg();
        fprintf(outFile,"MOV R%d, %d\n",reg,root->val);
        return reg;
    }
    int left=genCode(root->left);
    int right=genCode(root->right);
    char* op;
    switch(root->op){
        case '+':
            op="ADD";
            break;
        case '-':
            op="SUB";
            break;
        case '*':
            op="MUL";
            break;
        case '/':
            op="DIV";
            break;
    }
    fprintf(outFile,"%s R%d, R%d\n",op,left,right);
    freeReg();
    return left;
}

node* makeLeafNode(int n){
    node* ptr;
    ptr=makeOperatorNode(' ',NULL,NULL);
    ptr->val=n;
    return ptr;
}

node* makeOperatorNode(char op,node* left,node* right){
    node* ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->val=op;
    ptr->op=op;
    ptr->right=right;
    ptr->left=left;
    return ptr;
}

void printTree(node* root){
    for(int i=0;i<space;i++)printf(" ");
    if(root->op==' ')printf("%d\n",root->val);
    else{
        space+=2;
        printf("%c\n",root->op);
        printTree(root->left);
        printTree(root->right);
        space-=2;
    }
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

void yyerror(char *s){
    printf("%s\n",s);
}