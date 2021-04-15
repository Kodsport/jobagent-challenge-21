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
    
    lista = [str(random.randint(0,31556926000-4*10**5)) for _ in range(n)]
    print(n)
    print(" ".join(lista))

if __name__ == "__main__":
    main()
