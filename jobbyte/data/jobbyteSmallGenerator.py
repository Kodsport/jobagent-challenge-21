#!/usr/bin/env python3

import random
import collections
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def genPairs(n):
    S = list(range(n))
    random.shuffle(S)
    output = [str(x) for x in range(1, n + 1)]
    while len(S) >= 2:
        output[S[-1]], output[S[-2]] = output[S[-2]], output[S[-1]]
        S.pop()
        S.pop()
    return output

def genSmall(n):
    S = list(range(n))
    random.shuffle(S)
    output = [str(x) for x in range(1, n + 1)]

    while S:
        cyclen = random.randint(1, min(len(S), 7))
        for k in range(cyclen - 1):
            output[S[k]], output[S[k+1]] = output[S[k+1]], output[S[k]]
        for k in range(cyclen):
            S.pop()
    return output

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    arg = cmdlinearg("arg")
    if arg == "f":
        output = [str(x) for x in range(1, n + 1)]
    elif arg == "p":
        output = genPairs(n)
    elif arg == "r":
        output = genSmall(n)

    print(str(n))
    print(*output)
if __name__ == "__main__":
    main()
