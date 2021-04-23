#!/usr/bin/env bash

USE_SCORING=1
. ../../testdata_tools/gen.sh

use_solution sl.cpp

compile generateRandom.py
compile generatePermutations.py
compile genspecial.py
compile genspecial2.py

samplegroup
limits maxN=1000000
sample 1
sample 2
sample 3

group g1 1
limits maxN=5000
tc 1
tc 2
tc 3
tc allLetters generatePermutations n=26 m=2
tc permutations1 generatePermutations n=500 m=2
tc permutations2 generatePermutations n=5000 m=3
tc allsame-small generateRandom n=5000 m=2 s=1
tc onehuge-small generateRandom n=5000 m=4500 s=1
tc onehuge2-small generateRandom n=5000 m=4501 s=1
tc specialbig-small genspecial n=5000 m=4500
tc specialbig2-small genspecial n=5000 m=2501
tc special2-small genspecial2 n=5000
tc random0-small generateRandom n=5000 m=100 s=10
tc random1-small generateRandom n=5000 m=100 s=100
tc random2-small generateRandom n=5000 m=100 s=1000
tc random3-small generateRandom n=5000 m=630 s=10
tc random4-small generateRandom n=5000 m=630 s=100
tc random5-small generateRandom n=5000 m=630 s=1000
tc random6-small generateRandom n=5000 m=630 s=1000
tc random7-small generateRandom n=5000 m=3980 s=10
tc random8-small generateRandom n=5000 m=3980 s=100

group g2 1
limits maxN=1000000
include_group g1
tc permutations3 generatePermutations n=150000 m=4
tc allsame generateRandom n=1000000 m=2 s=1
tc onehuge generateRandom n=1000000 m=900000 s=1
tc onehuge2 generateRandom n=1000000 m=900001 s=1
tc specialbig genspecial n=1000000 m=900000
tc specialbig2 genspecial n=1000000 m=500001
tc special2 genspecial2 n=1000000
tc random0 generateRandom n=1000000 m=100 s=10
tc random1 generateRandom n=1000000 m=100 s=100
tc random2 generateRandom n=1000000 m=100 s=1000
tc random3 generateRandom n=1000000 m=100 s=10000
tc random4 generateRandom n=1000000 m=630 s=10
tc random5 generateRandom n=1000000 m=630 s=100
tc random6 generateRandom n=1000000 m=630 s=1000
tc random7 generateRandom n=1000000 m=630 s=1000
tc random8 generateRandom n=1000000 m=3980 s=10
tc random9 generateRandom n=1000000 m=3980 s=100
tc random10 generateRandom n=1000000 m=3980 s=1000
tc random11 generateRandom n=1000000 m=3980 s=1000
tc random12 generateRandom n=1000000 m=25110 s=10
tc random13 generateRandom n=1000000 m=25110 s=100
tc random14 generateRandom n=1000000 m=25110 s=100
tc random15 generateRandom n=1000000 m=25110 s=100
tc random16 generateRandom n=1000000 m=158480 s=10
tc random17 generateRandom n=1000000 m=158480 s=10
tc random18 generateRandom n=1000000 m=158480 s=10
tc random19 generateRandom n=1000000 m=158480 s=10
