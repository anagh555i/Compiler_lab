%{
    #include<stdio.h>    
    int val;
%}

%union{
    int Int;
}
%token<Int> NUM
%start E

%%

E   :   NUM '+' NUM {val=$1+$3;}
    |   NUM '*' NUM {val=$1*$3;}
    |   NUM '-' NUM {val=$1-$3;}
    |   NUM '/' NUM {val=$1/$3;}
    ;
%%

int main(){
    val=0;
    yyparse();
    printf("%d\n",val);
}

void yyerror(char *s){
    printf("%s\n",s);
}