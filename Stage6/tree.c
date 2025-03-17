#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Lnode* makeLnode(char* s,int num,Lnode* next){
    Lnode* ptr;
    ptr=(Lnode*)malloc(sizeof(Lnode));
    printf("make L node %s\n",s);
    ptr->s=s;
    ptr->num=num;
    ptr->next=next;
    return ptr;
}

void installG(char* name,int type, int size,int binding){
    Gsymbol* ptr;
    ptr=(Gsymbol*)malloc(sizeof(Gsymbol));
    ptr->name=name;
    ptr->type=type;
    ptr->binding=binding;
    ptr->size=size;
    ptr->paramlist=NULL;
    ptr->flabel=-1;
    ptr->fsymbols=NULL;
    ptr->next=Ghead;
    Ghead=ptr;
}
void installL(char* name,int type,int binding){
    Lsymbol* ptr;
    ptr=(Lsymbol*)malloc(sizeof(Lsymbol));
    ptr->name=name;
    ptr->type=type;
    ptr->binding=binding;
    ptr->next=NULL;
    // add ptr to end of list; to maintain relative order among arguments
    Lsymbol* temp=Lhead;
    while(temp && temp->next) temp=temp->next;
    if(temp) temp->next=ptr;
    else Lhead=ptr;
}

Gsymbol* lookUpG(char* name){
    printf("Lookup for %s\n",name);
    Gsymbol* ptr=Ghead;
    for(;ptr;ptr=ptr->next){
        if(strcmp(name,ptr->name)==0) return ptr;
    }
    return NULL;
}
Lsymbol* lookUpL(char* name){
    printf("Lookup for %s\n",name);
    Lsymbol* ptr=Lhead;
    for(;ptr;ptr=ptr->next){
        if(strcmp(name,ptr->name)==0) return ptr;
    }
    return NULL;
}

node* makeNode(int val,int type,Gsymbol* Gvar,Lsymbol* Lvar,int nodeType,node* left,node* right,node* center){
    node* ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->val=val;
    ptr->type=type;
    ptr->Gvar=Gvar;
    ptr->Lvar=Lvar;
    ptr->nodeType=nodeType;
    ptr->left=left;
    ptr->right=right;
    ptr->center=center;
    return ptr;
}

// void printTree(node* root){
//     if(root==NULL) return;
//     for(int i=0;i<space;i++)printf("|");
//     int temp=root->nodeType;
//     space+=3;
//     if(temp==tCONNECT) printf("->$\n");
//     else if(temp==1) printf("->%d\n",root->val);
//     else if(temp==2) printf("->%s\n",(root->var?root->var->name:"NULL"));
//     else if(temp==3) printf("->R\n");
//     else if(temp==4) printf("->W\n");
//     else if(temp==5) printf("->+\n");
//     else if(temp==6) printf("->-\n");
//     else if(temp==7) printf("->*\n");
//     else if(temp==8) printf("->/\n");
//     else if(temp==9) printf("->=\n");
//     else if(temp==10) printf("->LT\n");
//     else if(temp==11) printf("->GT\n");
//     else if(temp==12) printf("->LE\n");
//     else if(temp==13) printf("->GE\n");
//     else if(temp==14) printf("->EQ\n");
//     else if(temp==15) printf("->NEQ\n");
//     else if(temp==16) printf("->AND\n");
//     else if(temp==17) printf("->OR\n");
//     else if(temp==18) {
//         printf("->IF\n");
//         printTree(root->center);
//     }
//     else if(temp==19){
//         printf("->WHILE\n");
//         printTree(root->center);
//     }
//     printTree(root->left);
//     printTree(root->right);
//     space-=3;
// }
