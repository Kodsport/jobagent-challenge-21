#!/usr/bin/env python3

import random
import collections
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def genRandom(n):
    output = random.sample([[i+1,j] for i, j in enumerate(random.sample(list(range(1,n+1)),n))],n)
    print(str(n))

    for i in range(n): print(' '.join(map(str,output[i])))

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    genRandom(n)

if __name__ == "__main__":
    main()
