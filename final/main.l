%{
    #include "y.tab.h"  
    #include<string.h> 
    int count=1;
    int debuger=0; 
    void printLineNo();
    void debu(char* s);
%}

%%

"begin"   { debu(yytext); return begin;}
"end"    { debu(yytext); return end;}
"read"    { debu(yytext); return READ;}
"write"    {debu(yytext); return WRITE;}
"if"        { debu(yytext); return IF;}
"else"   { debu(yytext); return Else;}
"AND"     { debu(yytext); return AND;}
"OR"      { debu(yytext); return OR;}
"while"   {debu(yytext); return WHILE;}
"do"    {debu(yytext); return DO;}
"break"    {debu(yytext); return BREAK;}
"continue"    {debu(yytext); return CONTINUE;}
"repeat"    {debu(yytext); return REPEAT;}
"until"    {debu(yytext); return UNTIL;}
"decl"    {debu(yytext); return DECL;}
"enddecl"    {debu(yytext); return ENDDECL;}
"void"    {debu(yytext); return VOID;}
"return"    {debu(yytext); return RETURN;}
"type"    {debu(yytext); return TYPE;}
"endtype"    {debu(yytext); return ENDTYPE;}
"class"    {debu(yytext); return CLASS;}
"endclass"    {debu(yytext); return ENDCLASS;}
"extends"    {debu(yytext); return EXTENDS;}
"methods:"    {debu(yytext); return METHODBEGIN;}
"malloc"    {debu(yytext); return MALLOC;}
"->"    {debu(yytext); return ARROW;}
"main"    {debu(yytext);yylval.String=strdup(yytext); return MAIN;}
"null"    {debu(yytext); return Null;}
"new"    {debu(yytext); return NEW;}
"//"[a-zA-Z0-9 (|)|+|\-|*|/|;|%|=|<|>|,|&|{|}|\[|\]\.]+    {}
[!][=]  { debu(yytext); return NEQ;}
[=][=]  { debu(yytext); return EQ;}
[<][=]  { debu(yytext); return LE;}
[>][=]  { debu(yytext); return GE;}  

[0-9]+              {yylval.Int=atoi(yytext); return NUM;}
[(|)|+|\-|*|/|;|%|=|<|>|,|&|{|}|\[|\]\.]    {debu(yytext);return *yytext;}
[a-zA-Z][a-zA-Z0-9_]*    {
                            if(debuger)printf("found %s %d\n",yytext,yyleng);
                            yylval.String=strdup(yytext); return ID;
                        }
["][a-zA-Z0-9 *#!+=.\-:!]*["]      {   
                            if(debuger)printf("found %s %d\n",yytext,yyleng);
                            char *t=strtok(yytext,"\"");
                            // printf("%s\n",t);
                            yylval.String=strdup(t);
                            return LITERAL;
                        }
[ \t]             {;}
[\n]               {count++;if(debuger) printf("Line %d ####################\n",count);}
.                   {printf("Unexpected Character\n");
                    exit(0);}

%%
void printLineNo(){
    printf("@Line no.: %d\n",count);
}

void debu(char* s){
    if(debuger==0) return;
    printf("Found %s\n",s);
}

int yywrap(void){
    return 1;
}