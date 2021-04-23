#!/usr/bin/env bash

USE_SCORING=0
. ../../testdata_tools/gen.sh

use_solution sl.cpp

compile generateRandom.py
compile generatePermutations.py

sample 1
sample 2
sample 3

tc allLetters generatePermutations n=26 m=2
tc permutations2 generatePermutations n=500 m=2
tc permutations3 generatePermutations n=15000 m=3
tc allsame generateRandom n=100000 m=2 s=1
tc onehuge generateRandom n=100000 m=90000 s=1
tc onehuge2 generateRandom n=100000 m=90001 s=1
tc random0 generateRandom n=100000 m=10 s=10
tc random1 generateRandom n=100000 m=10 s=100
tc random2 generateRandom n=100000 m=10 s=1000
tc random3 generateRandom n=100000 m=10 s=10000
tc random4 generateRandom n=100000 m=63 s=10
tc random5 generateRandom n=100000 m=63 s=100
tc random6 generateRandom n=100000 m=63 s=1000
tc random7 generateRandom n=100000 m=63 s=1000
tc random8 generateRandom n=100000 m=398 s=10
tc random9 generateRandom n=100000 m=398 s=100
tc random10 generateRandom n=100000 m=398 s=1000
tc random11 generateRandom n=100000 m=398 s=1000
tc random12 generateRandom n=100000 m=2511 s=10
tc random13 generateRandom n=100000 m=2511 s=100
tc random14 generateRandom n=100000 m=2511 s=100
tc random15 generateRandom n=100000 m=2511 s=100
tc random16 generateRandom n=100000 m=15848 s=10
tc random17 generateRandom n=100000 m=15848 s=10
tc random18 generateRandom n=100000 m=15848 s=10
tc random19 generateRandom n=100000 m=15848 s=10
