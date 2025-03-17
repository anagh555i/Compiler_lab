#pragma once

// for type of variable
#define booltype 0
#define inttype 1
#define strtype 2
#define intptrtype 1
#define strptrtype 4
#define ptrtype 5
#define valtype 6
#define intarrtype 7
#define strarrtype 8
#define voidtype 9
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
#define tRETURN 29 // return statement
#define tFUNCT 30 // for function definitions
#define tFUNCTCALL 31 // for function calls

typedef struct node{
    int val;    //leaf node val
    int type;   // type of variable inttype or booltype or ....
    struct Gsymbol* Gvar; // pointer to global variable
    struct Lsymbol* Lvar; // pointer to local variable
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
    struct Lsymbol* paramlist; // parameter list for functions;
    int flabel ; // labels for functions, -1 if not a function;
    struct Lsymbol* fsymbols; // pointer to local symbol table for function
    Lnode* dim; // dimension for array variable // 1st is dimension and subsequent is size for each dim
}Gsymbol;

typedef struct Lsymbol{
    char* name; // name of variable
    int type; // type of variable
    int binding; // static memory address allocated, this one is relative, it only tells the relative position of each variable 
    struct Lsymbol* next;
}Lsymbol;



extern int space;

node* makeNode(int val,int type,Gsymbol* Gvar,Lsymbol* Lvar,int nodeType,node* left,node* right,node* center);
// void printTree(node* root);

extern Gsymbol* Ghead;

extern Lsymbol* Lhead;

void installG(char* name,int type, int size,int binding);
Gsymbol* lookUpG(char* name);

void installL(char* name,int type,int binding);
Lsymbol* lookUpL(char* name);

Lnode* makeLnode(char* s,int num,Lnode* next); //handy Listnode;


/* ATTRIBUTE STACK LOOKS LIKE THIS  
atri n
.....
atri 2
atri 1
return value
return address
old BP value (new BP points here)
local var 1
local var 2
..... 
local var m
reg r1 
reg r2
// new attribute stack for called function 
*/

/* // function callers duty to fill stack
reg r0
reg r1
.... 
reg rk
atri n
.....
atri 2
atri 1
return value
return address
*/

/* // functions duty to push to stack
old BP
local var 1
local var 2
..... 
local var m
*/