#!/usr/bin/env bash

USE_SCORING=0
. ../../testdata_tools/gen.sh

use_solution MA.py

compile jobbyteRandomGenerator.py
compile jobbyteSmallGenerator.py

sample 1
sample 2
sample 3

tc allPairs jobbyteSmallGenerator n=100000 arg=p
tc allPairs2 jobbyteSmallGenerator n=99999 arg=p
tc allCorrect jobbyteSmallGenerator n=100000 arg=f
tc allCorrect2 jobbyteSmallGenerator n=99999 arg=f
tc Small0 jobbyteSmallGenerator.py n=100000 arg=r
tc Small1 jobbyteSmallGenerator.py n=100000 arg=r
tc Small2 jobbyteSmallGenerator.py n=100000 arg=r
tc Small3 jobbyteSmallGenerator.py n=100000 arg=r
tc Small4 jobbyteSmallGenerator.py n=100000 arg=r
tc Small5 jobbyteSmallGenerator.py n=100000 arg=r
tc Small6 jobbyteSmallGenerator.py n=100000 arg=r
tc Small7 jobbyteSmallGenerator.py n=100000 arg=r
tc Small8 jobbyteSmallGenerator.py n=100000 arg=r
tc Small9 jobbyteSmallGenerator.py n=100000 arg=r
tc Small0 jobbyteRandomGenerator.py n=100000
tc Small1 jobbyteRandomGenerator.py n=100000
tc Small2 jobbyteRandomGenerator.py n=100000
tc Small3 jobbyteRandomGenerator.py n=100000
tc Small4 jobbyteRandomGenerator.py n=100000
tc Small5 jobbyteRandomGenerator.py n=100000
tc Small6 jobbyteRandomGenerator.py n=100000
tc Small7 jobbyteRandomGenerator.py n=100000
tc Small8 jobbyteRandomGenerator.py n=100000
tc Small9 jobbyteRandomGenerator.py n=100000
tc Small10 jobbyteRandomGenerator.py n=100000
tc Small11 jobbyteRandomGenerator.py n=100000
tc Small12 jobbyteRandomGenerator.py n=100000
tc Small13 jobbyteRandomGenerator.py n=100000
tc Small14 jobbyteRandomGenerator.py n=100000