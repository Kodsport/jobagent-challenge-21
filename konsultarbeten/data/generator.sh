#!/usr/bin/env bash

USE_SCORING=0
. ../../testdata_tools/gen.sh

use_solution MA.cpp

compile GenerateRandom.py
compile GenerateSpecial.py

sample 1
sample 2
sample 3


tc all_zeros GenerateSpecial n=100000 arg=z
tc close GenerateSpecial n=100000 arg=c
tc randomsmall0 GenerateRandom n=1000
tc randomsmall1 GenerateRandom n=1000
tc randomsmall2 GenerateRandom n=1000
tc randomsmed0 GenerateRandom n=9999
tc randomsmed1 GenerateRandom n=9999
tc randomsmed2 GenerateRandom n=9999
tc randomlrg0 GenerateRandom n=100000
tc randomlrg1 GenerateRandom n=100000
tc randomlrg2 GenerateRandom n=100000
tc randomlrg3 GenerateRandom n=100000
tc randomlrg4 GenerateRandom n=100000
tc randomlrg5 GenerateRandom n=100000
tc randomlrg6 GenerateRandom n=100000
tc randomlrg7 GenerateRandom n=100000
tc randomlrg8 GenerateRandom n=100000
tc randomlrg9 GenerateRandom n=100000
tc randomlrg10 GenerateRandom n=100000
tc randomlrg11 GenerateRandom n=100000