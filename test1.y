%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    int pos=0;
%}

%token DIGIT
%left '+'
%left '*'
%start start

%%

start   :   expr '\n'   {exit(1);}
        ;
expr    :   expr '+' expr   {printf("+ ");}
        |   expr '*' expr   {printf("* ");}
        |   '(' expr ')'
        |   DIGIT           {printf("NUM%d ",pos);}
        ;

%%

yyerror(char const *s){
    printf("Error %s\n",s);
}

yylex(){
    char c;
    c=getchar();
    if(isdigit(c)){
        pos++;
        return DIGIT;
    }
    else if(c==' ') yylex();
    else return c;
}

int main(){
    yyparse();
    return 1;
}