#pragma once
#include<stdbool.h>

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
#define tARRADDR 37 // for array node, to get address of array node
#define tLITERAL 27
#define tMOD 28
#define tRETURN 29 // return statement
#define tFUNCT 30 // for function definitions
#define tFUNCTCALL 31 // for function calls
#define tRECURSADDRATVAL 32 // for recursive address from value in reg
#define tRECURSADDR 33 // for recursive address calculation
#define tGETVAL 34 // for getting value from address node
#define tGETADDRATVAL 35 // for getting value from address node
#define tMALLOC 36 // 
// 37 used up
#define tNULL 38 // just returns -1 as pointer address. invalid address ie
#define tNEW 39 // 
#define tMETHODCALL 40 // 

typedef struct Methodlist {
    char *name;                      //name of the member function in the class
    struct Typetable *type;          //pointer to typetable, return type of  method
    struct Lsymbol *paramList;   //pointer to the head of the formal parameter list
    struct Lsymbol* fsymbols;
    int funcPosition;                //position of the function in the class table
    int flabel;                      //A label for identifying the starting address of the function's code in the memory
    struct node* fDefinition;    // pointer to function definition
    struct Methodlist *next;     //pointer to next Memberfunclist entry
}Methodlist;
typedef struct Fieldlist{
    char *name;              //name of the field
    int fieldIndex;          //the position of the field in the field list
    struct Typetable *type;  //pointer to type table entry of the field's type
    struct Typetable *ptrType;  //if type is pointer, pointer to type of pointer 
    struct Fieldlist *next;  //pointer to the next field
}Fieldlist;
typedef struct Typetable{   // DATA STRUCTURE FOR BOTH TYPES AND CLASSES node
    char *name;                 //type name
    int size;                   //size of the type, in this case no. of entries in fieldlist
    struct Fieldlist *fields;   //pointer to the head of fields list // null means default type
    struct Methodlist* vFunctPtr; // pointer to methods of the class
    int methodCount;
    int classIndex;            // -1 for types 
    struct Typetable* parent;    // points to parent class
    struct Typetable *next;     // pointer to the next type table entry
}Typetable;

typedef struct node{
    int val;    //leaf node val
    Typetable* type;   // type of variable, pointer to type table entry
    Typetable* ptrType;   // if type is of pointer type, ptrType points to the type of pointer
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
    Typetable* type; // type of variable, pointer to type table
    Typetable* ptrType; // if type is of pointer type, ptrType points to the type of pointer
    // if type is array, then ptrType points to type of array
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
    Typetable* type; // type of variable, pointer to type table entry
    Typetable* ptrType; // if type is of pointer type, ptrType points to type of pointer 
    int binding; // static memory address allocated, this one is relative, it only tells the relative position of each variable 
    struct Lsymbol* next;
}Lsymbol;

void InstallClass(char* name,int size,struct Fieldlist *fields,Typetable* parent,int methodCount,Methodlist* vFunctPtr);

void InstallType(char *name,int size, struct Fieldlist *fields);
void InstallMethod(Typetable* class,Typetable* parent,char *name,Lsymbol* paramList,Lsymbol* fsymbols,int funcPosition,int flabel,node* fDefinition,Typetable* type);
Methodlist* LookUpMethod(Typetable* class,char* name);
Typetable* lookUpType(char *name);
void createTypeTable();
Fieldlist* makeField(char* name,int fieldIndex,Typetable* type,Fieldlist* next);
Fieldlist* cloneFieldList(Fieldlist* f);
Typetable* makeTypeNode(char* name); // fieldlist temporary typenode maker
Fieldlist* LookupField(Typetable *type, char *name);
extern int space;

node* makeNode(int val,Typetable* type,Gsymbol* Gvar,Lsymbol* Lvar,int nodeType,node* left,node* right,node* center);
// void printTree(node* root);


void installG(char* name,Typetable* type, int size,int binding);
Gsymbol* lookUpG(char* name);

void installL(char* name,Typetable* type,Typetable* ptrType,int binding);
Lsymbol* lookUpL(char* name);

Lnode* makeLnode(char* s,int num,Lnode* next); //handy Listnode;

extern Gsymbol* Ghead;
extern Lsymbol* Lhead;
extern Typetable* Types;
extern Typetable* Classes;
extern int classCount;
extern int mlabel;

/* ATTRIBUTE STACK LOOK CONTENT  
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

typedef struct typeCapsule{
    Typetable* type;
    bool isPtr;
}typeCapsule;

void maketypeCapsule(Typetable* type,bool isPtr);

//  note that functions cannot return pointers yet