%{
    #include<stdio.h>    
    int integers=0,floats=0;
%}

%%

[0-9]+  {printf("%s\n",yytext);integers++;}
[0-9]+[.][0-9]+ {floats++;}

%%

int main(){
    yylex();
    printf("Integers:%d\nFloats:%d\n",integers,floats);
}

int yywrap(){
    return 1;
}