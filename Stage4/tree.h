#pragma once

// for type
#define inttype 0
#define booltype 1
#define Addresstype 2

// for nodeType
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

#define tdINT 24 // declare int
#define tdSTR 25 // declare string 
#define tdINTPTR 26 // declare int pointer
#define tdSTRPTR 27 // declare string pointer

#define tPTR 28


typedef struct node{
    int val;    //leaf node val
    int type;   // type of variable inttype or booltype
    // char *varname;  // name of variable
    struct Gsymbol* var; // pointer to variable
    int nodeType; // leaf node info read/write/+/*/...
    struct node* left;
    struct node* right;
    struct node* center; // for storing if and while condition
    struct Lnode* list;  // for any more lists that needs to be stored
}node;

typedef struct Gsymbol{
    char* name; // name of variable
    int type; // type of variable
    int size; // size of variable
    int binding; // static memory address allocated 
    struct Gsymbol* next;
}Gsymbol;

typedef struct Lnode{
    char* s;
    int num;
    struct Lnode* next;
}Lnode;


extern int space;

node* makeNode(int val,int type,Gsymbol* var,int nodeType,node* left,node* right,node* center);
void printTree(node* root);

extern Gsymbol* Ghead;

void install(char* name,int type, int size,int binding);
Gsymbol* lookUp(char* name);

Lnode* makeLnode(char* s,int num,Lnode* next); //handy Listnode;