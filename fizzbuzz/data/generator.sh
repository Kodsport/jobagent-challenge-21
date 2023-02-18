#!/usr/bin/env bash

. ../../testdata_tools/gen.sh

use_solution MA.py

compile FizzBuzz_generator.py

samplegroup
sample 1
sample 2
sample 3

group g1 1
tc 1
tc 2
tc 3
tc all_correct FizzBuzz_generator n=2 m=2 arg=c
tc all_correct2 FizzBuzz_generator n=1000 m=100 arg=c
tc all_correct3 FizzBuzz_generator n=10 m=15 arg=c
tc all_wrong FizzBuzz_generator n=2 m=2 arg=w
tc all_wrong2 FizzBuzz_generator n=1000 m=100 arg=w
tc all_wrong3 FizzBuzz_generator n=10 m=15 arg=w
tc random0 FizzBuzz_generator n=2 m=2 arg=r
tc random1 FizzBuzz_generator n=2 m=15 arg=r
tc random2 FizzBuzz_generator n=2 m=98 arg=r
tc random3 FizzBuzz_generator n=2 m=99 arg=r
tc random4 FizzBuzz_generator n=2 m=100 arg=r
tc random5 FizzBuzz_generator n=15 m=2 arg=r
tc random6 FizzBuzz_generator n=15 m=15 arg=r
tc random7 FizzBuzz_generator n=15 m=98 arg=r
tc random8 FizzBuzz_generator n=15 m=99 arg=r
tc random9 FizzBuzz_generator n=15 m=100 arg=r
tc random10 FizzBuzz_generator n=24 m=2 arg=r
tc random11 FizzBuzz_generator n=24 m=15 arg=r
tc random12 FizzBuzz_generator n=24 m=98 arg=r
tc random13 FizzBuzz_generator n=24 m=99 arg=r
tc random14 FizzBuzz_generator n=24 m=100 arg=r
tc random15 FizzBuzz_generator n=99 m=2 arg=r
tc random16 FizzBuzz_generator n=99 m=15 arg=r
tc random17 FizzBuzz_generator n=99 m=98 arg=r
tc random18 FizzBuzz_generator n=99 m=99 arg=r
tc random19 FizzBuzz_generator n=99 m=100 arg=r
tc random20 FizzBuzz_generator n=1000 m=2 arg=r
tc random21 FizzBuzz_generator n=1000 m=15 arg=r
tc random22 FizzBuzz_generator n=1000 m=98 arg=r
tc random23 FizzBuzz_generator n=1000 m=99 arg=r
tc random24 FizzBuzz_generator n=1000 m=100 arg=r
tc randomT0 FizzBuzz_generator n=2 m=2 arg=rt
tc randomT1 FizzBuzz_generator n=2 m=15 arg=rt
tc randomT2 FizzBuzz_generator n=2 m=98 arg=rt
tc randomT3 FizzBuzz_generator n=2 m=99 arg=rt
tc randomT4 FizzBuzz_generator n=2 m=100 arg=rt
tc randomT5 FizzBuzz_generator n=15 m=2 arg=rt
tc randomT6 FizzBuzz_generator n=15 m=15 arg=rt
tc randomT7 FizzBuzz_generator n=15 m=98 arg=rt
tc randomT8 FizzBuzz_generator n=15 m=99 arg=rt
tc randomT9 FizzBuzz_generator n=15 m=100 arg=rt
tc randomT10 FizzBuzz_generator n=24 m=2 arg=rt
tc randomT11 FizzBuzz_generator n=24 m=15 arg=rt
tc randomT12 FizzBuzz_generator n=24 m=98 arg=rt
tc randomT13 FizzBuzz_generator n=24 m=99 arg=rt
tc randomT14 FizzBuzz_generator n=24 m=100 arg=rt
tc randomT15 FizzBuzz_generator n=99 m=2 arg=rt
tc randomT16 FizzBuzz_generator n=99 m=15 arg=rt
tc randomT17 FizzBuzz_generator n=99 m=98 arg=rt
tc randomT18 FizzBuzz_generator n=99 m=99 arg=rt
tc randomT19 FizzBuzz_generator n=99 m=100 arg=rt
tc randomT20 FizzBuzz_generator n=1000 m=2 arg=rt
tc randomT21 FizzBuzz_generator n=1000 m=15 arg=rt
tc randomT22 FizzBuzz_generator n=1000 m=98 arg=rt
tc randomT23 FizzBuzz_generator n=1000 m=99 arg=rt
tc randomT24 FizzBuzz_generator n=1000 m=100 arg=rt
