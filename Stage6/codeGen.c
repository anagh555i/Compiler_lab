#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "codeGen.h"
#include "tree.h"

// Lhead;
// []

int genCode(node* root){
    if(root==NULL){
        printf("NULL codegen recieved\n");
        return 0;
    }
    else{
        printf("nodeType : %d\n",root->nodeType);
    }
    int reg;
    int addr;
    switch(root->nodeType){
        case tCONNECT: //connector
            if(root->left)genCode(root->left);
            if(root->right)genCode(root->right);
        break;
        case tCONST: //constants
            reg=getReg();
            fprintf(outFile,"MOV R%d, %d\n",reg,root->val);
            // handleWrite(reg);
            return reg;
        break;
        case tLITERAL:
            reg=getReg();
            fprintf(outFile,"MOV R%d, \"%s\"\n",reg,root->literal);
            return reg;
        break;
        case tVAR: //Variable
            reg=getReg();
            // fprintf(outFile,"MOV R%d, [%d]\n",reg,root->var->binding);
            if(root->Lvar) addr=root->Lvar->binding;
            else {
                fprintf(outFile,"MOV R%d, [%d]\n",reg,root->Gvar->binding);
                return reg;
            }
            fprintf(outFile,"MOV R%d, %d\n",reg,addr);
            fprintf(outFile,"ADD R%d,BP\n",reg);
            fprintf(outFile,"MOV R%d, [R%d]\n",reg,reg);
            return reg;
        break;
        case tARRVAL: //Variable
            reg=calculateAddress(root);
            fprintf(outFile,"JZ R%d, SEGFAULT!\n",reg);
            fprintf(outFile,"MOV R%d, [R%d]\n",reg,reg);
            return reg;
        break;
        case tARRADDR: //address of array access for assignments
            reg=calculateAddress(root);
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
            // if(WHILELABELS[1]!=-1) fprintf(outFile,"JMP L%d!\n",WHILELABELS[1]);
            if(breakLabels) fprintf(outFile,"JMP L%d!\n",breakLabels->num);
            else {
                yyerror("break outside looping statement\n");
                exit(0);
            }
        break;
        case tCONTINUE:
            // if(WHILELABELS[0]!=-1) fprintf(outFile,"JMP L%d!\n",WHILELABELS[0]);
            if(continueLabels) fprintf(outFile,"JMP L%d!\n",continueLabels->num);
            else{
                yyerror("continue outside looping statement\n");
                exit(0);
            }
        break;
        case tADDRESSOF:
            return handleAddressOf(root);
        break;
        case tRECURSADDR:
            return handleRecursAddress(root);
        break;
        case tRECURSADDRATVAL:
            return handleRecursAddressAtVal(root);
        break;
        case tGETVAL:
            return handleValueAt(root);
        break;
        case tGETADDRATVAL:
            return handleAddressAtVal(root);
        break;
        // case tVALUEAT :
        //     return handleValueAt(root);
        // break;
        case tMOD:
            return handleArithmetic(root);
        break;
        case tAND:
            return handleAnd(root);
        break;
        case tOR:
            return handleOR(root);
        break;
        case tFUNCTCALL:
            return handleFunctioncall(root);
        break;
        case tRETURN:
            return handleFunctionReturn(root);
        break;
        case tMALLOC:
            return handleMalloc(root);
        break;
        case tNULL:
            reg=getReg();
            fprintf(outFile,"MOV R%d, 0\n",reg);
            return reg;
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

void handleDoWhile(node* root){
    if(root==NULL || root->nodeType!=tDOWHILE) return;
    int L1=label++;
    int L2=label++;
    continueLabels=makeLnode("",L1,continueLabels);
    breakLabels=makeLnode("",L2,breakLabels);
    genCode(root->left); // making sure it runs once, then the while loop itself
    fprintf(outFile,"L%d:\n",L1); 
    int reg=genCode(root->center);
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L2);
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    continueLabels=continueLabels->next;
    breakLabels=breakLabels->next;
    freeReg();
}
void handleRepeatUntil(node* root){
    if(root==NULL || root->nodeType!=tREPEATUNTIL) return;
    int L1=label++;
    int L2=label++;
    continueLabels=makeLnode("",L1,continueLabels);
    breakLabels=makeLnode("",L2,breakLabels);
    genCode(root->left); // making sure it runs once, then the while loop itself
    fprintf(outFile,"L%d:\n",L1); 
    int reg=genCode(root->center);
    fprintf(outFile,"JNZ R%d, L%d!\n",reg,L2); // jump if non zero
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    continueLabels=continueLabels->next;
    breakLabels=breakLabels->next;
    freeReg();
}
void handleWhile(node* root){
    if(root==NULL || root->nodeType!=tWHILE) return;
    int L1=label++;
    fprintf(outFile,"L%d:\n",L1); 
    int L2=label++;
    continueLabels=makeLnode("",L1,continueLabels);
    breakLabels=makeLnode("",L2,breakLabels);
    int reg=genCode(root->center);
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L2);
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    continueLabels=continueLabels->next;
    breakLabels=breakLabels->next;
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

int handleAnd(node* root){
    int r1=genCode(root->left);
    int r2=genCode(root->right);
    fprintf(outFile,"MUL R%d,R%d\n",r1,r2);
    freeReg(); // free r2
    int l1=label++;
    int l2=label++;
    return r1;
}
int handleOR(node* root){
    int r1=genCode(root->left);
    int r2=genCode(root->right);
    fprintf(outFile,"ADD R%d,R%d\n",r1,r2);
    freeReg(); // free r2
    int l1=label++;
    int l2=label++;
    return r1;
}

int handleFunctionReturn(node* root){
    printf("%s\n",currFunction->name);
    if(root->left && (currFunction->type != root->left->type)) yyerror("type mismatch");
    // printf("return type check complete\n");
    int reg=genCode(root->left);
    int r1=getReg();
    fprintf(outFile,"MOV R%d, BP\n",r1);
    fprintf(outFile,"SUB R%d, 2\n",r1);
    fprintf(outFile,"JZ R%d, SEGFAULT!\n",r1);
    fprintf(outFile,"MOV [R%d], R%d\n",r1,reg);
    Lsymbol* lvar=currFunction->fsymbols;
    for(;lvar;lvar=lvar->next){
        // printf("%s\n",lvar->name);
        fprintf(outFile,"POP R0\n");
    }
    fprintf(outFile,"POP BP\n");
    fprintf(outFile,"RET\n");
}

int handleFunctioncall(node* root){
    int i;
    for(i=0;i<currReg;i++) fprintf(outFile,"PUSH R%d\n",i); // registers in use;
    push_reverse(root->left); // push space for arguments
    fprintf(outFile,"PUSH R0\n"); // space for return value;
    fprintf(outFile,"CALL F%d!\n",root->Gvar->flabel);
    int reg=getReg();
    fprintf(outFile,"POP R%d\n",reg); //poping return value
    pop_reverse(root->left); // poppig spaces of arguments
    for(i=currReg-2;i>=0;i--) fprintf(outFile,"POP R%d\n",i); // registers taken back;
    return reg;
}

void push_reverse(node* root){
    if(root==NULL) return ;
    push_reverse(root->center);
    int reg=genCode(root);
    fprintf(outFile,"PUSH R%d\n",reg);
    freeReg();
}
void pop_reverse(node* root){
    if(root==NULL) return ;
    pop_reverse(root->center);
    int reg=getReg();
    fprintf(outFile,"POP R%d\n",reg);
    freeReg();
}

int calculateAddress(node* root){
    int reg=getReg();
    node*ptr=root->left; // indexes in chain
    Lnode* x=root->Gvar->dim->next; // size of each index in chain
    int size=root->Gvar->size;
    int r1=getReg();
    int r2;
    fprintf(outFile,"MOV R%d, %d\n",r1,size);
    fprintf(outFile,"MOV R%d, %d\n",reg,root->Gvar->binding);
    for(;x && ptr;x=x->next,ptr=ptr->left){
        printf("iteration %d %d %d\n",currReg,x->num,size);
        fprintf(outFile,"DIV R%d, %d\n",r1,x->num);
        r2=genCode(ptr);
        fprintf(outFile,"MUL R%d, R%d\n",r2,r1);
        fprintf(outFile,"ADD R%d, R%d\n",reg,r2);
        freeReg();
    }
    r2=getReg();
    fprintf(outFile,"MOV R%d, %d\n",r1,size);
    fprintf(outFile,"ADD R%d, %d\n",r1,root->Gvar->binding); //r1 contians limit of arr size
    fprintf(outFile,"LE R%d, R%d\n",r1,reg); //store 0 in r1 if value in reg is greater than that in r1
    fprintf(outFile,"MOV R%d, \"out of bound\"\n",r2);
    fprintf(outFile,"PUSH R%d\n",r2);
    fprintf(outFile,"JNZ R%d, ERRORMESS!\n",r1);
    fprintf(outFile,"POP R%d\n",r2);
    freeReg();
    freeReg();
    return reg;
}

int handleValueAt(node* root){
    int reg=genCode(root->left);
    fprintf(outFile,"JZ R%d, SEGFAULT!\n",reg);
    fprintf(outFile,"MOV R%d,[R%d]\n",reg,reg);
    return reg;
}

int handleAddressOf(node* root){
    int reg=getReg();
    int addr;
    if(root->left->Lvar) addr=root->left->Lvar->binding;
    else{
        fprintf(outFile,"MOV R%d, %d\n",reg,root->left->Gvar->binding);
        return reg;
    }
    fprintf(outFile,"MOV R%d, %d\n",reg,addr);
    fprintf(outFile,"ADD R%d, BP\n",reg);
    return reg;
}
int handleRecursAddress(node* root){
    int addr=genCode(root->left);
    int offset=genCode(root->right);
    fprintf(outFile,"ADD R%d, R%d\n",addr,offset);
    freeReg();
    return addr;
}
int handleRecursAddressAtVal(node* root){
    int addr=genCode(root->left);
    int offset=genCode(root->right);
    fprintf(outFile,"JZ R%d, SEGFAULT!\n",addr);
    fprintf(outFile,"MOV R%d, [R%d]\n",addr,addr);
    fprintf(outFile,"ADD R%d, R%d\n",addr,offset);
    freeReg();
    return addr;
}
int handleAddressAtVal(node* root){
    int addr=genCode(root->left);
    fprintf(outFile,"JZ R%d, SEGFAULT!\n",addr);
    fprintf(outFile,"MOV R%d, [R%d]\n",addr,addr);
    return addr;
}

void handleAssignment(node* root){
    int reg=genCode(root->right);
    int addr=genCode(root->left);
    fprintf(outFile,"JZ R%d, SEGFAULT!\n",addr);
    fprintf(outFile,"MOV [R%d], R%d\n",addr,reg);
    freeReg();
    freeReg();
}

int handleArithmetic(node* root){
    int left=genCode(root->left);
    int right=genCode(root->right);
    char* op;
    switch(root->nodeType){
        case tADD:
            op="ADD";
            break;
        case tSUB:
            op="SUB";
            break;
        case tMUL:
            op="MUL";
            break;
        case tDIV:
            op="DIV";
            break;
        case tMOD:
            op="MOD";
            break;
    }
    fprintf(outFile,"%s R%d, R%d\n",op,left,right);
    freeReg();
    return left;
}

void handleWrite(int Wreg){
    int r;
    for(r=0;r<currReg;r++){
        fprintf(outFile,"PUSH R%d\n",r);
    }
    int reg=getReg();
    // int r1=getReg();
    // printf("FROM HANDLE WRITE Wreg is R%d, extra using R%d and R%d\n",Wreg,reg,r1);
    // fprintf(outFile,"MOV R%d, R%d\n",r1,Wreg);

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
    
    // fprintf(outFile,"MOV R%d, R%d\n",Wreg,r1);
    // freeReg();
    freeReg();
    for(r--;r>=0;r--) fprintf(outFile,"POP R%d\n",r);
}
int handleMalloc(node* root){
    int r;
    for(r=0;r<currReg;r++){
        fprintf(outFile,"PUSH R%d\n",r);
    }
    int reg=getReg();
    fprintf(outFile,"MOV R%d, \"Alloc\"\n",reg); //funct code
    fprintf(outFile,"PUSH R%d\n",reg);
    fprintf(outFile,"MOV R%d, 8\n",reg); //arg 1=8,size of memory block
    fprintf(outFile,"PUSH R%d\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);  //arg 2
    fprintf(outFile,"PUSH R%d\n",reg);  //arg 3
    fprintf(outFile,"PUSH R%d\n",reg);  // space for return value
    
    fprintf(outFile,"CALL 0\n");
    fprintf(outFile,"BRKP\n");

    int reg2=getReg();
    fprintf(outFile,"POP R%d\n",reg);   // return value has memory address location
    fprintf(outFile,"POP R%d\n",reg2);
    fprintf(outFile,"POP R%d\n",reg2);
    fprintf(outFile,"POP R%d\n",reg2);
    fprintf(outFile,"POP R%d\n",reg2);
    freeReg();
    for(r--;r>=0;r--) fprintf(outFile,"POP R%d\n",r);
    return reg;
}

void initializeHeapSet(){
    int reg=getReg();
    fprintf(outFile,"MOV R%d, \"Heapset\"\n",reg); //funct code
    fprintf(outFile,"PUSH R%d\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);  //arg1
    fprintf(outFile,"PUSH R%d\n",reg);  //arg 2
    fprintf(outFile,"PUSH R%d\n",reg);  //arg 3
    fprintf(outFile,"PUSH R%d\n",reg);  // space for return value
    
    fprintf(outFile,"CALL 0\n");
    fprintf(outFile,"BRKP\n");

    fprintf(outFile,"POP R%d\n",reg);   // return value has memory address location
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    freeReg();
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
    int r;
    for(r=0;r<currReg;r++){
        fprintf(outFile,"PUSH R%d\n",r);
    }
    int reg=getReg();

    fprintf(outFile,"MOV R%d, \"Read\"\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, -1\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    if(root->left->Lvar) {
        fprintf(outFile,"MOV R%d,%d\n",reg,root->left->Lvar->binding);
        fprintf(outFile,"ADD R%d, BP\n",reg);
    }
    else fprintf(outFile,"MOV R%d, %d\n",reg,root->left->Gvar->binding);
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
    for(r--;r>=0;r--) fprintf(outFile,"POP R%d\n",r);
}
void genExit(){
    fprintf(outFile,"EXITCODE:\n"); 
    fprintf(outFile,"MOV R0, \"Exit\"\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"CALL 0\n");
}
void genSegmenationFault(){
    int reg=getReg();
    fprintf(outFile,"SEGFAULT:\n");
    fprintf(outFile,"MOV R%d,\"**seg fault**\"\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);
    fprintf(outFile,"JMP ERRORMESS!\n");
    freeReg();
}
void genErrorHandler(){
    int reg=getReg();
    fprintf(outFile,"ERRORMESS:\n");
    fprintf(outFile,"POP R%d\n",reg);
    handleWrite(reg);
    fprintf(outFile,"JMP EXITCODE!\n");
}