%{
    #include<stdio.h>    
    int integers=0,floats=0;
%}

num [0-9]+

%%

{num}  {printf("%s\n",yytext);integers++;}
{num}[.]{num} {floats++;}
.   {;}

%%

int main(const char* args[]){
    printf("%s\n",args[0]);
    FILE *fp=fopen(args[0],"r");
    yyin=fp;
    yylex();
    printf("Integers:%d\nFloats:%d\n",integers,floats);
}

int yywrap(){
    return 1;
}