#!/usr/bin/env python3

import random
import collections
import sys

def genRandom(n):
    output = random.shuffle([[i,j] for i, j in enumerate(random.shuffle(*range(1,n+1)))])
    print(str(n)+'\n')
    for i in range(n): print(' '.join(output[i]))
    
def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    genRandom(n)

if __name__ == "__main__":
    main()
