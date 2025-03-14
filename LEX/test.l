%{
    #include<stdio.h>
    #include<stdlib.h>    

    
%}

num [0-9]+

%%

{num} {printf("found %d\n",atoi(yytext));}
.   {;}

%%

int main(int argc,const char** args){
    printf("%s\n",args[1]);
    FILE *fp=fopen(args[1],"r");
    yyin=fp;
    yylex();
}

int yywrap(){
    return 1;
}