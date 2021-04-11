#!.*python3\b
import random
import collections
import sys

def correctSeq(m):
    l = []
    for i in range(1,m+1):
        s = ""
        if i % 3 == 0:
            s += "Fizz"
        if i % 5 == 0:
            s += "Buzz"
        if len(s) == 0:
            s = str(i)
        l.append(s)
    return l

def genRandom(n,m, fixed_thresh = 0):
    correct = correctSeq(m)
    output = "{} {}".format(n,m) + "\n"
    thresh = random.uniform(0,1)

    for i in range(n):
        if not fixed_thresh:
            thresh = random.uniform(0,1)
        line = ""

        for j in range(m):
            if random.uniform(0,1) > thresh:
                line += correct[j] + " "
            else:
                line += random.choice(correct) + " "
        output += line[:-1] + "\n"
    
    print(output[:-1])

def allSame(n,m, correct = 1):
    output = "{} {}".format(n,m) + "\n"
    if correct:
        output += "".join([" ".join(correctSeq(m)) + "\n" for _ in range(n)])
    else:
        output += (("x "*m)[:-1] + "\n")*n
    print(output[:-1])

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg("n"))
    m = int(cmdlinearg('m'))
    arg = cmdlinearg('arg')

    if arg == 'r':
        genRandom(n,m,0)
    if arg == "rt":
        genRandom(n,m,1)
    if arg == "w":
        allSame(n,m,0)
    if arg == "c":
        allSame(n,m,1)



def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    #return default[name]

if __name__ == "__main__":
    main()