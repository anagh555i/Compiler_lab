%option noyywrap
%{
    #include<stdio.h>    
%}

num [0-9]+

%%
{num} {printf("Found %d %d\n",atoi(yytext),yyleng); return atoi(yytext);}
"If"    {printf("Found %s %d\n",yytext,yyleng);}

%%

int main(){
    int number=yylex();
    printf("Returned Number=%d\n",number);
    return 1;
}