%{

    #include "y.tab.h"
    #include<stdio.h>
    #include<stdlib.h>

%}

%%

[0-9]+  {yylval.Int=atoi(yytext); return NUM;}
[+|-|*|/] {return *yytext;}

%%

int yywrap(){
    return 1;
}