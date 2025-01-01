%{
    #include "y.tab.h"    
%}

%%

begin   {return begin;}
end     {return end;}
read    {return READ;}
write   {return WRITE;}   

[0-9]+              {yylval.Int=atoi(yytext); return NUM;}
[(|)|+|\-|*|/|;|=]    {return *yytext;}
[a-z]               {yylval.Char=*yytext; return ID;}
[ \n\t]             {;}
.                   {printf("Unexpected Character\n");}

%%

int yywrap(void){
    return 1;
}