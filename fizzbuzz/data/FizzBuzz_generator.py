#!/usr/bin/env python3
import random
import collections
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

def correct_seq(m):
    l = []
    for i in range(1,m+1):
        s = ""
        if i % 3 == 0:
            s += "fizz"
        if i % 5 == 0:
            s += "buzz"
        if len(s) == 0:
            s = str(i)
        l.append(s)
    return l

def gen_random(n, m, fixed_thresh):
    print(n, m)
    correct = correct_seq(m)
    thresh = random.uniform(0,1)

    for i in range(n):
        if not fixed_thresh:
            thresh = random.uniform(0,1)

        vals = []
        for j in range(m):
            if random.uniform(0,1) > thresh:
                vals.append(correct[j])
            else:
                if thresh > 0.9:
                    vals.append("0" + random.choice(correct))
                else:
                    vals.append(random.choice(correct))
                
        print(*vals)

def all_same(n, m, correct):
    print(n, m)
    if correct:
        line = " ".join(correct_seq(m))
    else:
        line = " ".join(["x"] * m)
    for _ in range(n):
        print(line)

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg("m"))
    arg = cmdlinearg("arg")

    if arg == "r":
        gen_random(n,m,0)
    if arg == "rt":
        gen_random(n,m,1)
    if arg == "w":
        all_same(n,m,0)
    if arg == "c":
        all_same(n,m,1)

if __name__ == "__main__":
    main()
