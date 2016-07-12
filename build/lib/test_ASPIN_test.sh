#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/joe/gr-ASPIN/lib
export PATH=/home/joe/gr-ASPIN/build/lib:$PATH
export LD_LIBRARY_PATH=/home/joe/gr-ASPIN/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-ASPIN 
