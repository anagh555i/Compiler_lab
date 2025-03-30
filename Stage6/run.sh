#!/bin/bash/

lex main.l 
yacc -d main.y
gcc lex.yy.c y.tab.c tree.c codeGen.c -o out
./out

lex Linker.l
gcc lex.yy.c
./a.out

curr=${pwd}

cd /home/anagh/PROGRAMMING/xsm_expl/xsm_expl
./xsm -l library.lib -e ../../Compiler_lab/Stage6/a.xsm
cd "$curr"