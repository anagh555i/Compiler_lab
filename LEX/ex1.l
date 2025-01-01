%option noyywrap

%{
    #include<stdio.h> 
    int lines=1,words=0,characters=0;   
%}

%%

[a-zA-Z0-9]+   {words++;characters+=yyleng;}
[\n]    {lines++;}
[ ]     {;}
.   {;}

%%

int main(){
    yylex();
    printf("Lines:%d\nWords:%d\nCharacters:%d",characters?lines:0,words,characters);
}