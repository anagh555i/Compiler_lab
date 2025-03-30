#!/bin/bash/

curr=${pwd}

cd /home/anagh/PROGRAMMING/xsm_expl/xsm_expl
./xsm -l library.lib -e ../../Compiler_lab/Stage6/test.xsm --debug
cd "$curr"