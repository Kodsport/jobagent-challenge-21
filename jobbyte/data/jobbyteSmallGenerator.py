#!/usr/bin/env python3

import random
import collections
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def genPairs(n):
    shuffled = random.sample(list(range(1,1+n)), n)
    output = []
    i = n-1
    while i >= 3:
        output.append([shuffled[i], shuffled[i-1]])
        output.append([shuffled[i-1],shuffled[i]])
        i -= 2
    for j in range(i):
        output.append([shuffled[j], shuffled[j+1]])
    output.append([shuffled[i], shuffled[0]])
    return output

def genSmall(n):
    transform = dict(zip(list(range(n)),random.sample(list(range(1,1+n)), n)))
    output = []
    
    i = 0
    while i < n:
        iters = min(random.randint(1,7), n - i - 1)
        for _ in range(iters):
            output.append([transform[i], transform[i+1]])
            i += 1
        output.append([transform[i], transform[i-iters]])
        i += 1
    return output

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    arg = cmdlinearg("arg")
    if arg == "f":
        output = [[i,i] for i in range(1,1+n)]
    elif arg == "p":
        output = genPairs(n)
    elif arg == "r":
        output = genSmall(n)

    print(str(n))
    for i in range(n): print(' '.join(map(str,output[i])))
if __name__ == "__main__":
    main()
