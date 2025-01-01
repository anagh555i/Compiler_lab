%{
    #include<stdio.h>
%}

%%

if |
else | 
while {printf("Found %s\n",yytext);}

exit {printf("Founc %s\n",yytext); return 0;}

.   {printf("unexpected character\n");}

%%

int main(){
    printf("Welcom to lex programming\nEnter text:");
    yylex();
}

int yywrap(){
    return 1;
}