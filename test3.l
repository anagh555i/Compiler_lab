%{
    #include<stdio.h>
    // op [-|+|*|^|=]  just do the below way
%}

num [0-9]+
op [*-/=^]

%%
"if"    {printf("Found %s\n",yytext);}
"ifelse"    {printf("Found %s\n",yytext);}
{num} {printf("Found %s\n",yytext);}
{op}    {printf("Found %s\n",yytext);}
%%

int main(){
    // FILE *fp=fopen("input.txt","r");
    // yyin=fp;
    return yylex(); 
}

int yywrap(){
    return 1;
}