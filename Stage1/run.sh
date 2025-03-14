#!/bin/bash/

lex main.l 
yacc -d main.y
gcc lex.yy.c y.tab.c -o out
./out

curr=${pwd}

cd /home/anagh/PROGRAMMING/xsm_expl/xsm_expl
./xsm -l library.lib -e ../../Compiler_lab/Stage1/a.xsm
cd "$curr"