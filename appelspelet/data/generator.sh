#!/usr/bin/env bash

USE_SCORING=1
. ../../testdata_tools/gen.sh

use_solution js.py

compile gencat.py

samplegroup
limits maxN=1000000
sample 1
sample 2
sample 3

group g1 1
limits maxN=1000
tc 1
tc 2
tc 3
tc rand1-small gencat n=948
tc rand2-small gencat n=104
tc rand3-small gencat n=129
tc rand4-small gencat n=987
tc rand5-small gencat n=411
tc rand6-small gencat n=198
tc rand7-small gencat n=562
tc rand8-small gencat n=537
tc rand9-small gencat n=435
tc rand10-small gencat n=437
tc big-small gencat n=999
tc max-small gencat n=1000

group g2 1
limits maxN=1000000
include_group g1
tc rand1 gencat n=948731
tc rand2 gencat n=109754
tc rand3 gencat n=123689
tc rand4 gencat n=549387
tc rand5 gencat n=478911
tc rand6 gencat n=129876
tc rand7 gencat n=587462
tc rand8 gencat n=548937
tc rand9 gencat n=483135
tc rand10 gencat n=439827
tc big1 gencat n=999999
tc big2 gencat n=999998
tc big3 gencat n=999997
tc big4 gencat n=999995
tc big-beata gencat n=999971
tc big-beata-2 gencat n=887505
tc big-beata-3 gencat n=465512
tc max gencat n=1000000
