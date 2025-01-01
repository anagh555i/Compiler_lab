// C declarations
%{
    void yyerror(char *s);
    #include<stdio.h>
    #include<stdlib.h>
    int buffer[52]; // fir storing a-z and A-Z;
    void updatebuffer(char c,int val);
    int getvalue(char c);
%}

// yacc definitions
%union {int num; char id;}
%start start
%token print
%token exit_command
%token <num> number 
%token <id> identifier
%type <num> start exp term //non terminals; All these map to type int
%type <id> assignment

%%

start   : assignment ';'    {;}
        | exit_command ';'  {exit(EXIT_SUCCESS);}
        | print exp ';'     {printf("Printing %d\n",$2);}
        | start assignment ';' {;}
        | start print exp ';'  {printf("Printing %d\n",$3);}
        | start exit_command ';' {exit(EXIT_SUCCESS);}
        ;

assignment  : identifier '=' exp {updatebuffer($1,$3);} 
            ;

exp     : term {$$=$1;}
        | exp '+' term {$$=$1 + $3;}
        | exp '-' term {$$=$1 - $3;}
        | exp '*' term {$$=$1 * $3;}
        | exp '/' term {$$=$1 / $3;}
        ;

term    : identifier {$$=getvalue($1);}
        | number {$$=$1;}

%%

void updatebuffer(char c,int val){
    int i;
    if(c>='a' && c<='z') i=c-'a';
    else if(c>='A' && c<='Z') i=c-'A'+26;
    else {
        printf("Out of bound Buffe access\n");
        return;
    }
    buffer[i]=val;
    return;
}

int getvalue(char c){
    int i;
    if(c>='a' && c<='z') i=c-'a';
    else if(c>='A' && c<='Z') i=c-'A'+26;
    else {
        printf("Out of bound Buffe access\n");
        return -1;
    }
    return buffer[i];
}

void yyerror(char *s){
    fprintf(stderr,"%s\n",s);
}

int main(){
    for(int i=0;i<52;i++) buffer[i]=0;
    printf("Enter code below\n");
    return yyparse();
}