#!/usr/bin/env bash

USE_SCORING=0
. ../../testdata_tools/gen.sh

use_solution MA.py

compile jobbyteRandomGenerator.py
compile jobbyteSmallGenerator.py

sample 1
sample 2
sample 3

tc allPairs jobbyteSmallGenerator n=300000 arg=p
tc allPairs2 jobbyteSmallGenerator n=299999 arg=p
tc allCorrect jobbyteSmallGenerator n=300000 arg=f
tc allCorrect2 jobbyteSmallGenerator n=299999 arg=f
tc Small0 jobbyteSmallGenerator n=300000 arg=r
tc Small1 jobbyteSmallGenerator n=300000 arg=r
tc Small2 jobbyteSmallGenerator n=300000 arg=r
tc Small3 jobbyteSmallGenerator n=300000 arg=r
tc Small4 jobbyteSmallGenerator n=300000 arg=r
tc Small5 jobbyteSmallGenerator n=300000 arg=r
tc Small6 jobbyteSmallGenerator n=300000 arg=r
tc Small7 jobbyteSmallGenerator n=300000 arg=r
tc Small8 jobbyteSmallGenerator n=300000 arg=r
tc Small9 jobbyteSmallGenerator n=300000 arg=r
tc Big jobbyteRandomGenerator n=300000
tc Big1 jobbyteRandomGenerator n=300000
tc Big2 jobbyteRandomGenerator n=300000
tc Big3 jobbyteRandomGenerator n=300000
tc Big4 jobbyteRandomGenerator n=300000
tc Big5 jobbyteRandomGenerator n=300000
tc Big6 jobbyteRandomGenerator n=300000
tc Big7 jobbyteRandomGenerator n=300000
tc Big8 jobbyteRandomGenerator n=300000
tc Big9 jobbyteRandomGenerator n=300000
tc Big10 jobbyteRandomGenerator n=300000
tc Big11 jobbyteRandomGenerator n=300000
tc Big12 jobbyteRandomGenerator n=300000
tc Big13 jobbyteRandomGenerator n=300000
tc Big14 jobbyteRandomGenerator n=300000
