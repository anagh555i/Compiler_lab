#pragma once

// for type of variable
#define booltype 0
#define inttype 1
#define strtype 2
#define intptrtype 3
#define strptrtype 4
#define ptrtype 5
#define valtype 6
#define intarrtype 7
#define strarrtype 8
// #define addresstype 7

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
#define tADDRESSOF 24 // for &ptr
#define tVALUEAT 25 // for *ptr
#define tARRVAL 26 // for array node, val stores offset
#define tLITERAL 27
#define tMOD 28

typedef struct node{
    int val;    //leaf node val
    int type;   // type of variable inttype or booltype or ....
    struct Gsymbol* var; // pointer to variable
    int nodeType; // leaf node info read/write/+/*/...
    struct node* left;
    struct node* right;
    struct node* center; // for storing if and while condition
    struct Lnode* list;  // for any more lists that needs to be stored
    char* literal; // for storing literals;
}node;

typedef struct Lnode{
    char* s;
    int num;
    struct Lnode* next;
}Lnode;

typedef struct Gsymbol{
    char* name; // name of variable
    int type; // type of variable
    int size; // size of variable
    int binding; // static memory address allocated 
    struct Gsymbol* next;
    Lnode* dim; // dimension for array variable // 1st is dimension and subsequent is size for each dim
}Gsymbol;


extern int space;

node* makeNode(int val,int type,Gsymbol* var,int nodeType,node* left,node* right,node* center);
void printTree(node* root);

extern Gsymbol* Ghead;

void install(char* name,int type, int size,int binding);
Gsymbol* lookUp(char* name);

Lnode* makeLnode(char* s,int num,Lnode* next); //handy Listnode;