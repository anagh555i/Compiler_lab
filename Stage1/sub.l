%{
    #include "y.tab.h"    
%}

%%

[0-9]+  {yylval.Int=atoi(yytext); return NUM;}
[+|\-|*|/]   {yylval.Char=yytext[0]; return OP;}
[ \n\t]     {;}
.       {;}

%%

int yywrap(void){
    return 1;
}