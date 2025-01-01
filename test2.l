%{
    #include<stdio.h>    
%}

%%

[a-zA-Z]+ printf("Found %s\n",yytext);

%%

int main(){
    return yylex();
}

int yywrap(){
    printf("end of file reached\n");
    return 1;
}