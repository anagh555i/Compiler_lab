#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "parser.h"
#include "tree.h"

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

int genCode(node* root){
    int reg;
    switch(root->nodeType){
        case tCONNECT: //connector
            if(root->left)genCode(root->left);
            if(root->right)genCode(root->right);
        break;
        case tCONST: //constants
            reg=getReg();
            fprintf(outFile,"MOV R%d, %d\n",reg,root->val);
            return reg;
        break;
        case tVAR: //Variable
            reg=getReg();
            if(root->type==Addresstype){
                printf("%s\n",root->var->name);
                fprintf(outFile,"MOV R%d, %d\n",reg,root->var->binding);
                printf("MOV R%d, %d\n",reg,root->var->binding);
            }
            else fprintf(outFile,"MOV R%d, [%d]\n",reg,root->var->binding);
            return reg;
        break;
        case tPTR: //pointer access
            reg=getReg();
            fprintf(outFile,"MOV R%d, [%d]\n",reg,root->var->binding);
            fprintf(outFile,"MOV R%d, [R%d]\n",reg,reg);
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
        case tdINT:
            Lnode* ptr1=root->list;
            for(;ptr1;ptr1=ptr1->next){
                if(lookUp(ptr1->s)){
                    yyerror("Variable already Declared");
                    exit(0);
                }
                install(ptr1->s,tdINT,1,SP++);
            }
            printf("Ghead is %s\n",Ghead->name);
            fprintf(outFile,"MOV SP, %d\n",SP);
        break;
        case tdSTR:
            Lnode* ptr=root->list;
            for(;ptr;ptr=ptr->next){
                if(lookUp(ptr->s)){
                    yyerror("Variable already Declared");
                    exit(0);
                }
                install(ptr->s,tdSTR,1,SP++);
            }
            fprintf(outFile,"MOV SP, %d\n",SP);
        break;
    }
    if(root->nodeType>4 && root->nodeType<9){ //+-*/
        return handleArithmetic(root);
    }
    else if(root->nodeType>9 && root->nodeType<16){ // < > <= >= == !=
        return handleComparison(root);
    }
    return 100;// junk
}
void handleAssignment(node* root){
    printf("ASSGNMNT\n");
    int reg=genCode(root->right);
    int reg2=getReg();
    if(root->left->nodeType==tPTR) fprintf(outFile,"MOV R%d, [%d]",reg2,root->left->var->binding);
    else fprintf(outFile,"MOV R%d, %d",reg2,root->left->var->binding);
    fprintf(outFile,"MOV [R%d], R%d\n",reg2,reg);
    freeReg();
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
    fprintf(outFile,"MOV SP,%d\n",SP); // set stack pointer to after the declarations;
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
    int reg=getReg();

    fprintf(outFile,"MOV R%d, \"Read\"\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, -1\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, %d\n",reg,root->left->var->binding);
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