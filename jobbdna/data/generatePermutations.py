#!/usr/bin/env python3
import random
import sys
import itertools

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    
    stringlist = random.sample([''.join(i) for i in itertools.permutations([chr(x) for x in range(97, 123)], m)], n // m)
    
    bigstring = ''.join(stringlist + [chr(random.randint(97, 122)) for _ in range(n % m)])
    split = random.randint(0,n)

    print(n,m)
    print(bigstring[split:] + bigstring[:split])

if __name__ == "__main__":
    main()
