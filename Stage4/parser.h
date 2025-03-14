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
void handleIfElse(node* root);
int handleComparison(node* root);
void handleWhile(node* root);
void handleDoWhile(node* root);
void handleRepeatUntil(node* root);

bool isArithmetic(node* left, node* right);
bool isBoolean(node* left, node* right);
