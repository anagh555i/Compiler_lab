#!/bin/bash/

curr=${pwd}

cd /home/anagh/PROGRAMMING/xsm_expl/xsm_expl
./xsm -l library.lib -e ../../Compiler_lab/Stage4_enhanced/a.xsm --debug
cd "$curr"