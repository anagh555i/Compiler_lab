#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include "y.tab.h"
extern void yyerror(char* s);
extern void debug(int i);

// void maketypeCapsule(Typetable* type,bool isPtr){
//     typeCapsule* ptr=(typeCapsule*)malloc(sizeof(typeCapsule));
//     ptr->type=type;
//     ptr->isPtr=isPtr;
//     return ptr;
// }

Lnode* makeLnode(char* s,int num,Lnode* next){
    Lnode* ptr;
    ptr=(Lnode*)malloc(sizeof(Lnode));
    // printf("make L node %s\n",s);
    ptr->s=s;
    ptr->num=num;
    ptr->next=next;
    return ptr;
}

void createTypeTable(){
    char* defaultType;
    defaultType=strdup("int");
    InstallType(defaultType,1,NULL);
    defaultType=strdup("string");
    InstallType(defaultType,1,NULL);
    defaultType=strdup("ptr");
    InstallType(defaultType,1,NULL);
    defaultType=strdup("bool");
    InstallType(defaultType,1,NULL);
    defaultType=strdup("array");
    InstallType(defaultType,1,NULL);
    defaultType=strdup("null");
    InstallType(defaultType,1,NULL);
}

Typetable* makeTypeNode(char* name){
    Typetable* ptr=(Typetable*)malloc(sizeof(Typetable));
    ptr->name=name;
    ptr->size=0;
    ptr->fields=NULL;
    ptr->next=NULL;
    return ptr;
}

void InstallType(char *name,int size, struct Fieldlist *fields){
    Typetable* ptr=Types;
    for(;ptr;ptr=ptr->next){
        if(strcmp(ptr->name,name)==0) return; // return if type name already exists in type table;
    }
    ptr=Classes;
    for(;ptr;ptr=ptr->next){
        if(strcmp(ptr->name,name)==0) return; // return if type name already exists in class table;
    }
    ptr=(Typetable*)malloc(sizeof(Typetable));
    ptr->name=name;
    ptr->size=size;
    ptr->fields=fields;
    ptr->next=Types;
    ptr->classIndex=-1;
    ptr->methodCount=0;
    ptr->parent=NULL;
    ptr->vFunctPtr=NULL;
    Types=ptr;
}

// void InstallMethod(Typetable* class,Typetable* parent,char *name,Lsymbol* paramList,Lsymbol* fsymbols,int funcPosition,int flabel,node* fDefinition,Typetable* type){
//     Typetable* sibling=Classes;
//     Methodlist* methods=NULL;
//     // what if the method already exist for the class;
//     methods=class->vFunctPtr;
//     for(;methods;methods=methods->next){
//         if(strcmp(methods->name,name)==0) yyerror("duplicate method declarations");
//     }
//     Methodlist* method=(Methodlist*)malloc(sizeof(Methodlist));
//     method->name=name;
//     method->fDefinition=fDefinition;
//     method->flabel=mlabel++;
//     method->next=class->vFunctPtr;
//     method->paramList=paramList;
//     method->fsymbols=fsymbols;
//     method->type=type; // return type
//     // only function position in virtual function table remaining;
//     // printf("METHOD INSTALL %s %s\n",class->name,name);
//     if(parent) methods=parent->vFunctPtr;
//     for(;methods;methods=methods->next){ // search in parent vFunctiontable;
//         if(strcmp(methods->name,name)==0){
//             method->funcPosition=methods->funcPosition;
//             // printf("METHOD POSITION: %d\n",method->funcPosition);
//             class->methodCount++;
//             class->vFunctPtr=method;
//             return;
//         }
//     }
//     for(;sibling;sibling=sibling->next){
//         if(sibling->parent!=parent) continue;
//         methods=sibling->vFunctPtr;
//         for(;methods;methods=methods->next){ //search in each siblings vFunctiontable
//             if(strcmp(methods->name,name)==0){
//                 method->funcPosition=methods->funcPosition;
//                 // printf("METHOD POSITION: %d\n",method->funcPosition);
//                 class->methodCount++;
//                 class->vFunctPtr=method;
//                 return;
//             }
//         }
//     }
//     // if no function of the name exist anywhere;
//     if(parent){
//         method->funcPosition=parent->methodCount++;
//         // printf("METHOD POSITION: %d\n",method->funcPosition);
//         class->vFunctPtr=method;
//         class->methodCount++;
//     }
//     else {
//         method->funcPosition=class->methodCount++;
//         class->vFunctPtr=method;
//         // printf("METHOD POSITION: %d\n",method->funcPosition);
//     }

// }
void InstallMethod(Typetable* class,Typetable* parent,char *name,Lsymbol* paramList,Lsymbol* fsymbols,int funcPosition,int flabel,node* fDefinition,Typetable* type){
    Typetable* sibling=Classes;
    Methodlist* methods=NULL;
    // what if the method already exist for the class;
    methods=class->vFunctPtr;
    for(;methods;methods=methods->next){
        bool b=true; // same
        // printf("---------------- %s %s\n",methods->name,name);
        Lsymbol* newParam=NULL, *oldParam;
        if(paramList)newParam=paramList;
        oldParam=methods->paramList;
        while(newParam && oldParam){
            // printf("params: %s %s\n",oldParam->name,newParam->name);
            if(newParam->binding>0 && oldParam->binding>0 ) break;
            if(newParam->binding>0 && oldParam->binding<0 || newParam->binding<0 && oldParam->binding>0){
                b=false;
                break;
            }
            if(newParam->type != oldParam->type){
                b=false;
                break;
            }
            newParam=newParam->next;
            oldParam=oldParam->next;
        }
        if(newParam && newParam->binding<0) b=false;
        if(b && strcmp(methods->name,name)==0) yyerror("duplicate method declarations");
    }
    Methodlist* method=(Methodlist*)malloc(sizeof(Methodlist));
    method->name=name;
    method->fDefinition=fDefinition;
    method->flabel=mlabel++;
    method->next=class->vFunctPtr;
    method->paramList=paramList;
    method->fsymbols=fsymbols;
    method->type=type; // return type
    // only function position in virtual function table remaining;
    // printf("METHOD INSTALL %s %s\n",class->name,name);
    if(parent) methods=parent->vFunctPtr;
    for(;methods;methods=methods->next){ // search in parent vFunctiontable;
        bool b=true; // same
        // printf("---------------- %s %s\n",methods->name,name);
        Lsymbol* newParam=NULL, *oldParam;
        if(paramList) newParam=paramList;
        oldParam=methods->paramList;
        while(newParam && oldParam){
            // printf("params: %s %s\n",oldParam->name,newParam->name);
            if(newParam->binding>0 && oldParam->binding>0 ) break;
            if(newParam->binding>0 && oldParam->binding<0 || newParam->binding<0 && oldParam->binding>0){
                b=false;
                break;
            }
            // printf("types: %s %s\n",newParam->type->name,oldParam->type->name);
            if(newParam->type != oldParam->type){
                b=false;
                break;
            }
            newParam=newParam->next;
            oldParam=oldParam->next;
        }
        if(b && strcmp(methods->name,name)==0){
            method->funcPosition=methods->funcPosition;
            // printf("METHOD - POSITION: %d\n",method->funcPosition);
            class->methodCount++;
            class->vFunctPtr=method;
            return;
        }
    }
    for(;sibling;sibling=sibling->next){
        if(sibling->parent!=parent) continue;
        methods=sibling->vFunctPtr;
        for(;methods;methods=methods->next){ //search in each siblings vFunctiontable
            bool b=true; // same
            Lsymbol* newParam=NULL, *oldParam;
            if(paramList)newParam=paramList;
            oldParam=methods->paramList;
            while(newParam && oldParam){
                if(newParam->binding>0 && oldParam->binding>0 ) break;
                if(newParam->binding>0 && oldParam->binding<0 || newParam->binding<0 && oldParam->binding>0){
                    b=false;
                    break;
                }
                if(newParam->type != oldParam->type){
                    b=false;
                    break;
                }
                newParam=newParam->next;
                oldParam=oldParam->next;
            }
            if(b && strcmp(methods->name,name)==0){
                method->funcPosition=methods->funcPosition;
                // printf("METHOD_POSITION: %d\n",method->funcPosition);
                class->methodCount++;
                class->vFunctPtr=method;
                return;
            }
        }
    }
    // if no function of the name exist anywhere;
    if(parent){
        method->funcPosition=parent->methodCount++;
        // printf("METHOD @ POSITION: %d\n",method->funcPosition);
        class->vFunctPtr=method;
        class->methodCount++;
    }
    else {
        method->funcPosition=class->methodCount++;
        class->vFunctPtr=method;
        // printf("METHOD #POSITION: %d\n",method->funcPosition);
    }

}

// Methodlist* LookUpMethod(Typetable* class,char* name){
//     Methodlist* methods=class->vFunctPtr;
//     for(;methods;methods=methods->next){
//         if(strcmp(methods->name,name)==0) return methods;
//     }
//     // now check for method in childrens
//     Typetable* ptr=Classes;
//     for(;ptr;ptr=ptr->next){
//         if(ptr->parent==class){
//             methods=ptr->vFunctPtr;
//             for(;methods;methods=methods->next){
//                 if(strcmp(methods->name,name)==0) return methods;
//             }
//         }
//     }
//     return NULL;
// }

Methodlist* LookUpMethod(Typetable* class,char* name,node* arguments){
    Methodlist* methods=class->vFunctPtr;
    for(;methods;methods=methods->next){
        bool b=true; // same;
        Lsymbol* params=methods->paramList;
        if(params) params=params->next;
        node* args=arguments;
        while(params && args){
            if(params->binding>0) b=false;
            if(params->type != args->type){
                b=false;
                break;
            }
            params=params->next;
            args=args->center;
        }
        if((params && params->binding<0) || args) b=false;
        if(b && strcmp(methods->name,name)==0) return methods;
    }
    // now check for method in childrens
    Typetable* ptr=Classes;
    for(;ptr;ptr=ptr->next){
        if(ptr->parent==class){
            methods=ptr->vFunctPtr;
            for(;methods;methods=methods->next){
                bool b=true; // same;
                Lsymbol* params=methods->paramList;
                if(params) params=params->next;
                node* args=arguments;
                while(params && args){
                    if(params->binding>0) b=false;
                    if(params->type != args->type){
                        b=false;
                        break;
                    }
                    params=params->next;
                    args=args->center;
                }
                if((params && params->binding<0) || args) b=false;
                if(strcmp(methods->name,name)==0) return methods;
            }
        }
    }
    return NULL;
}

void InstallClass(char* name,int size,struct Fieldlist *fields,Typetable* parent,int methodCount,Methodlist* vFunctPtr){
    Typetable* ptr=Types;
    for(;ptr;ptr=ptr->next){
        if(strcmp(ptr->name,name)==0) return; // return if class name already exists in type table;
    }
    ptr=Classes;
    for(;ptr;ptr=ptr->next){
        if(strcmp(ptr->name,name)==0) return; // return if class name already exists in class table;
    }
    ptr=(Typetable*)malloc(sizeof(Typetable));
    ptr->name=name;
    ptr->size=size;
    ptr->fields=fields;
    ptr->next=Classes;
    ptr->classIndex=classCount++;
    ptr->methodCount=methodCount;
    ptr->parent=parent;
    ptr->vFunctPtr=vFunctPtr;
    Classes=ptr;
}

Fieldlist* cloneFieldList(Fieldlist* f){
    Fieldlist* clone=NULL;
    for(;f;f=f->next){
        clone=makeField(f->name,f->fieldIndex,f->type,clone);
    }
    return clone;
}
Fieldlist* makeField(char* name,int fieldIndex,Typetable* type,Fieldlist* next){
    Fieldlist* ptr;
    ptr=(Fieldlist*)malloc(sizeof(Fieldlist));
    ptr->name=name;
    ptr->fieldIndex=fieldIndex;
    ptr->type=type;
    ptr->ptrType=type;
    ptr->next=next;
    return ptr;
}
Fieldlist* LookupField(Typetable *type, char *name){
    // if(type) printf("ptr Type is %s\n",type->name);
    // else printf("Ptr type empty\n");
    if(!type) yyerror("No such type ");
    Fieldlist* ptr=type->fields;
    // printf("fields in %s\n",type->name);
    for(;ptr;ptr=ptr->next){
        // printf("%s %s\n",ptr->name,name);
        // else printf("name points to null");
        if(strcmp(ptr->name,name)==0){
            // printf("hit\n");
            return ptr;
        }
    }
    // printf("end of fields");
    return NULL;
}

Typetable* lookUpType(char *name){
    Typetable* ptr=Types;
    // printf("Types searching in type table:\n");
    for(;ptr;ptr=ptr->next){
        // printf("%s ",ptr->name);
        if(strcmp(ptr->name,name)==0) {
            // printf("\n");
            return ptr; 
        }
    }
    ptr=Classes;
    // printf("Types searching in class table:\n");
    for(;ptr;ptr=ptr->next){
        // printf("%s ",ptr->name);
        if(strcmp(ptr->name,name)==0) {
            // printf("\n");
            return ptr; 
        }
    }
    // printf("\n");
    return NULL;
}

void installG(char* name,Typetable* type, int size,int binding){
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
void installL(char* name,Typetable* type,Typetable* ptrType,int binding){
    Lsymbol* ptr;
    ptr=(Lsymbol*)malloc(sizeof(Lsymbol));
    ptr->name=name;
    ptr->type=type;
    ptr->ptrType=ptrType;
    ptr->binding=binding;
    ptr->next=NULL;

    // add ptr to end of list; to maintain relative order among arguments
    Lsymbol* temp=Lhead;
    while(temp && temp->next) temp=temp->next;
    if(temp) temp->next=ptr;
    else Lhead=ptr;
}

Gsymbol* lookUpG(char* name){
    // printf("Lookup for %s\n",name);
    Gsymbol* ptr=Ghead;
    for(;ptr;ptr=ptr->next){
        if(strcmp(name,ptr->name)==0) return ptr;
    }
    return NULL;
}
Lsymbol* lookUpL(char* name){
    // printf("Lookup for %s\n",name);
    Lsymbol* ptr=Lhead;
    for(;ptr;ptr=ptr->next){
        if(strcmp(name,ptr->name)==0) return ptr;
    }
    return NULL;
}

node* makeNode(int val,Typetable* type,Gsymbol* Gvar,Lsymbol* Lvar,int nodeType,node* left,node* right,node* center){
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
    // for(int i=0;i<space;i++)printf("|");
//     int temp=root->nodeType;
//     space+=3;
    // if(temp==tCONNECT) printf("->$\n");
    // else if(temp==1) printf("->%d\n",root->val);
    // else if(temp==2) printf("->%s\n",(root->var?root->var->name:"NULL"));
    // else if(temp==3) printf("->R\n");
    // else if(temp==4) printf("->W\n");
    // else if(temp==5) printf("->+\n");
    // else if(temp==6) printf("->-\n");
    // else if(temp==7) printf("->*\n");
    // else if(temp==8) printf("->/\n");
    // else if(temp==9) printf("->=\n");
    // else if(temp==10) printf("->LT\n");
    // else if(temp==11) printf("->GT\n");
    // else if(temp==12) printf("->LE\n");
    // else if(temp==13) printf("->GE\n");
    // else if(temp==14) printf("->EQ\n");
    // else if(temp==15) printf("->NEQ\n");
    // else if(temp==16) printf("->AND\n");
    // else if(temp==17) printf("->OR\n");
//     else if(temp==18) {
        // printf("->IF\n");
//         printTree(root->center);
//     }
//     else if(temp==19){
        // printf("->WHILE\n");
//         printTree(root->center);
//     }
//     printTree(root->left);
//     printTree(root->right);
//     space-=3;
// }
//debug