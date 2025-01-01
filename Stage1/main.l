%{
    #include "y.tab.h"    
%}

%%

[0-9]+  {yylval.Int=atoi(yytext); return NUM;}
[+|\-|*|/|(|)]   {yylval.Char=yytext[0]; return yytext[0];}
[ \n\t]     {;}
.       {;}

%%

int yywrap(void){
    return 1;
}