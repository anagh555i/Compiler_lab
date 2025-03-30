#pragma once
#include "tree.h"
#include<stdio.h>
#include<stdbool.h>

extern FILE* outFile;
extern int currReg;
extern int varBase;
extern int SP;
extern int label;
extern int WHILELABELS[];
extern void yyerror(char* s);
extern Lnode* breakLabels; // stores the values to break running loops
extern Lnode* continueLabels; // stores the values to continue running loops 
extern Lsymbol* Lhead;
extern Gsymbol* currFunction;

int genCode(node* root);
void genHeader();
int getReg();
void freeReg();
void handleWrite(int Wreg);
void handleRead(node* root);
int handleArithmetic(node* root);
void handleAssignment(node* root);
void genExit();
void genErrorHandler();
void genSegmenationFault();
void handleIfElse(node* root);
int handleComparison(node* root);
void handleWhile(node* root);
void handleDoWhile(node* root);
void handleRepeatUntil(node* root);
int handleAddressOf(node* root);
int handleRecursAddress(node* root);
int handleRecursAddressAtVal(node* root);
int handleValueAt(node* root);
int handleAddressAtVal(node* root);
int calculateAddress(node* root);
int handleFunctioncall(node* root);
int handleFunctionReturn(node* root);
void push_reverse(node* root);
void pop_reverse(node* root);
int handleAnd(node* root);
int handleOR(node* root);
int handleMalloc(node* root);
void initializeHeapSet();
