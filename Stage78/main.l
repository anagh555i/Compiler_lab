%{
    #include "y.tab.h"  
    #include<string.h> 
    int count=1; 
    void printLineNo();
%}

%%

"begin"   { printf("Found %s\n",yytext); return begin;}
"end"    { printf("Found %s\n",yytext); return end;}
"read"    { printf("Found %s\n",yytext); return READ;}
"write"    {printf("Found %s\n",yytext); return WRITE;}
"if"        { printf("Found %s\n",yytext); return IF;}
"else"   { printf("Found %s\n",yytext); return Else;}
"AND"     { printf("Found %s\n",yytext); return AND;}
"OR"      { printf("Found %s\n",yytext); return OR;}
"while"   {printf("Found %s\n",yytext); return WHILE;}
"do"    {printf("Found %s\n",yytext); return DO;}
"break"    {printf("Found %s\n",yytext); return BREAK;}
"continue"    {printf("Found %s\n",yytext); return CONTINUE;}
"repeat"    {printf("Found %s\n",yytext); return REPEAT;}
"until"    {printf("Found %s\n",yytext); return UNTIL;}
"decl"    {printf("Found %s\n",yytext); return DECL;}
"enddecl"    {printf("Found %s\n",yytext); return ENDDECL;}
"void"    {printf("Found %s\n",yytext); return VOID;}
"return"    {printf("Found %s\n",yytext); return RETURN;}
"type"    {printf("Found %s\n",yytext); return TYPE;}
"endtype"    {printf("Found %s\n",yytext); return ENDTYPE;}
"class"    {printf("Found %s\n",yytext); return CLASS;}
"endclass"    {printf("Found %s\n",yytext); return ENDCLASS;}
"extends"    {printf("Found %s\n",yytext); return EXTENDS;}
"methods:"    {printf("Found %s\n",yytext); return METHODBEGIN;}
"malloc"    {printf("Found %s\n",yytext); return MALLOC;}
"->"    {printf("Found %s\n",yytext); return ARROW;}
"main"    {printf("Found %s\n",yytext);yylval.String=strdup(yytext); return MAIN;}
"null"    {printf("Found %s\n",yytext); return Null;}
"new"    {printf("Found %s\n",yytext); return NEW;}
"//"[a-zA-Z0-9 (|)|+|\-|*|/|;|%|=|<|>|,|&|{|}|\[|\]\.]+    {}
[!][=]  { printf("Found %s\n",yytext); return NEQ;}
[=][=]  { printf("Found %s\n",yytext); return EQ;}
[<][=]  { printf("Found %s\n",yytext); return LE;}
[>][=]  { printf("Found %s\n",yytext); return GE;}  

[0-9]+              {yylval.Int=atoi(yytext); return NUM;}
[(|)|+|\-|*|/|;|%|=|<|>|,|&|{|}|\[|\]\.]    {printf("found %s\n",yytext);return *yytext;}
[a-zA-Z][a-zA-Z0-9_]*    {
                            printf("found %s %d\n",yytext,yyleng);
                            yylval.String=strdup(yytext); return ID;
                        }
["][a-zA-Z0-9 *#!+=.\-:!]*["]      {   
                            printf("found %s %d\n",yytext,yyleng);
                            char *t=strtok(yytext,"\"");
                            // printf("%s\n",t);
                            yylval.String=strdup(t);
                            return LITERAL;
                        }
[ \t]             {;}
[\n]               {count++;printf("Line %d ####################\n",count);}
.                   {printf("Unexpected Character\n");
                    exit(0);}

%%
void printLineNo(){
    printf("@Line no.: %d\n",count);
}

int yywrap(void){
    return 1;
}