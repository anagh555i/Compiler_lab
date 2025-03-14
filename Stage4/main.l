%{
    #include "y.tab.h"  
    #include<string.h>  
%}

%%

"begin"   { printf("Found %s\n",yytext); return begin;}
"end"    { printf("Found %s\n",yytext); return end;}
"read"    { printf("Found %s\n",yytext); return READ;}
"write"    {printf("Found %s\n",yytext); return WRITE;}
"if"        { printf("Found %s\n",yytext); return IF;}
"else"   { printf("Found %s\n",yytext); return Else;}
"then"    { printf("Found %s\n",yytext); return then;}
"endif"   { printf("Found %s\n",yytext); return ENDIF;}
"AND"     { printf("Found %s\n",yytext); return AND;}
"OR"      { printf("Found %s\n",yytext); return OR;}
"while"   {printf("Found %s\n",yytext); return WHILE;}
"do"    {printf("Found %s\n",yytext); return DO;}
"endwhile" {printf("Found %s\n",yytext); return ENDWHILE;}
"break"    {printf("Found %s\n",yytext); return BREAK;}
"continue"    {printf("Found %s\n",yytext); return CONTINUE;}
"repeat"    {printf("Found %s\n",yytext); return REPEAT;}
"until"    {printf("Found %s\n",yytext); return UNTIL;}
"decl"    {printf("Found %s\n",yytext); return DECL;}
"enddecl"    {printf("Found %s\n",yytext); return ENDDECL;}
"int"    {printf("Found %s\n",yytext); return INT;}
"string"    {printf("Found %s\n",yytext); return STR;}
[!][=]  { printf("Found %s\n",yytext); return NEQ;}
[=][=]  { printf("Found %s\n",yytext); return EQ;}
[<][=]  { printf("Found %s\n",yytext); return LE;}
[>][=]  { printf("Found %s\n",yytext); return GE;}  

[0-9]+              {yylval.Int=atoi(yytext); return NUM;}
[(|)|+|\-|*|/|;|=|<|>|,|&]    {printf("found %s\n",yytext);return *yytext;}
[a-zA-Z][a-zA-Z0-9]*    {
                            printf("found %s %d\n",yytext,yyleng);
                            yylval.String=strdup(yytext); return ID;
                        }
[ \n\t]             {;}
.                   {printf("Unexpected Character\n");}

%%

int yywrap(void){
    return 1;
}