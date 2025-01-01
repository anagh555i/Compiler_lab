%{
    #include<stdio.h>    
%}

%%

"//"[a-zA-Z0-9]*    {printf("Found %s\n",yytext);}
"/*"(.)*"*/" {printf("Found %s\n",yytext);}

%%

int main(){
    yylex();
}

int yywrap(){
    return 1;
}