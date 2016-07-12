#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/root/gr-ASPIN/lib
export PATH=/home/root/gr-ASPIN/ebuild/lib:$PATH
export LD_LIBRARY_PATH=/home/root/gr-ASPIN/ebuild/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-ASPIN 
