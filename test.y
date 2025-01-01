%token NUM

%%

S   : E
    ;

E   : E '+' F
    | F
    ;

F   : '(' E ')'
    | '-' F
    | NUM
    ;

%%