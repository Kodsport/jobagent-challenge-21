#!/usr/bin/env python3
import random
import collections
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    arg = cmdlinearg("arg")

    if arg == "z":
        print(n)
        print(" ".join(['0' for _ in range(n)]))
    if arg == "c":
        print(n)
        print(" ".join([str(x) for x in range(0,4*n, 4)]))
    


if __name__ == "__main__":
    main()