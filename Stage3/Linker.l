%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h> 
    #include<stdbool.h>

    /*  ASSUMPTIONS OF THIS PROGRAM
        -> All label declarations are of form [A-Z][:]
        -> There are no free lines between Instructions in program
        -> All label calls are of form [A-Z][!]
    */

    typedef struct node{
        char* label;
        int val;
        struct node* next;
    }node;

    int rem=8;
    bool mode=false;// 0-> first parse
                    // 1-> second parse
    int base=2048;
    
    FILE *temp;
    FILE *fp;
    FILE *outFile;

    node* head;
    node* makeNode(char* label,int val,node* next);
    int getAddress(char* label);

%}

%%

[A-Z]+[:][\n]   {
                char temp[100];
                int n=strlen(yytext);
                strncpy(temp,yytext,n-1);
                temp[n-2]='\0';
                head=makeNode(temp,base,head);
                }
[A-Z]+[!]       {
                if(mode){
                    char temp[100];
                    int n=strlen(yytext);
                    strncpy(temp,yytext,n);
                    temp[n-1]='\0';
                    n=getAddress(temp);
                    fprintf(outFile,"%d",n);
                }
                else{
                    fprintf(outFile,"%s",yytext);
                }
                }
[\n]            {
                if(rem){ rem--; base++;}
                else base+=2;
                fprintf(outFile,"\n");
                }
.               {fprintf(outFile,"%c",*yytext);}

%%

int main(){

    fp=fopen("a.xsm","r");
    temp=fopen("temp.xsm","w");
    outFile=temp;
    head=NULL;
    yyin=fp;
    head=NULL;
    yylex();
    node* ptr=head;
    for(;ptr;ptr=ptr->next)printf("%s %d",ptr->label,ptr->val);
    printf("\n");

    fclose(fp);
    fclose(temp);
    mode=true;
    
    fp=fopen("a.xsm","w");
    temp=fopen("temp.xsm","r");
    outFile=fp;
    yyin=temp;
    yylex();

    remove("temp.xsm");
    return 1;
}

int yywrap(){
    // printf("Label translation and pruning complete\n");
    return 1;
}

int getAddress(char* label){
    for(node* ptr=head;ptr;ptr=ptr->next) if(strcmp(ptr->label,label)==0) return ptr->val;
    return 0;
}
node* makeNode(char* label,int val,node* next){
    node* ptr=(node*)malloc(sizeof(node));
    int n=strlen(label);
    ptr->label=(char*)malloc(sizeof(char)*(n+1));
    strcpy(ptr->label,label);
    ptr->val=val;
    ptr->next=next;
    return ptr;
}