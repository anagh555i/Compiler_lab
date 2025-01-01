%{
    #include<stdio.h>
    #include<ctype.h>
    #include<stdbool.h>
    bool isvalid=true;
%}

%token  ALPHA
%token NUM
%start start

%%

start   :   ALPHA rem {;}
        ;
rem     :   rem ALPHA   {;}
        |   rem NUM     {;}
        |   ALPHA       {;}
        |   NUM         {;}
        |   'EOF'        {return 1;}
        ;

%%

yyerror(char const *s){
    printf("Invalid variable name\n");
    isvalid=false;
    printf("%s\n",s);
    return ;
}

yylex(){
    char c;
    c=getchar();
    if(isdigit(c)) return NUM;
    else if(isalpha(c)) return ALPHA;
    else if(c=='\n') return yylex();
    else if(c==EOF) return c;
    return c;
}

int main(){
    yyparse();
    if(isvalid) printf("Valid variable name :)\n");
    return 1;
}