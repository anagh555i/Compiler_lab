%{
    #include<stdio.h> 
    #include<stdlib.h>
    #include<ctype.h>
    int depth=0;   
%}

%start start
%token DIGIT
%token COND
%token I 
%token F

%%

start   :   statement '\n'      {;}
        ;
statement   :   IF '(' COND ')' statement    {depth++;}
            |   DIGIT   {printf("Found digit\n");}
            |   '{' statement '}'
            ;
IF      :   I F {/*printf("Found if\n")*/;}
        ;

%%

yylex(){
    char c;
    c=getchar();
    /* printf("*%c*\n",c); */
    if(isdigit(c)) return DIGIT;
    else if(c==' ' || c=='\n' || c=='\t') return yylex();
    else if(c=='+'||c=='-') return COND;
    else if(c=='i') return I;
    else if(c=='f') return F;
    return c;
}

yyerror(char const *s){
    printf("%s\n",s);
    return;
}

int main(){
    yyparse();
    printf("%d\n",depth);
    return 1;
}
