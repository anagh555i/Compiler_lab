%{
    #include<stdio.h>
%}

%%

[A]([a-zA-Z]{3})    {printf("Found %s\n",yytext);}
.       {printf("what %s\n",yytext);}

%%

int main(){
    yylex();
}

int yywrap(){
    return 1;
}

