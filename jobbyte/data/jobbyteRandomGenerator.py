#!/usr/bin/env python3

import random
import collections
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def genRandom(n):
    x = list(range(1, n+1))
    random.shuffle(x)
    print(len(x))
    print(*x)

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    genRandom(n)

if __name__ == "__main__":
    main()
