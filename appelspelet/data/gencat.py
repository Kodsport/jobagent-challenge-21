import sys
import random

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

random.seed(int(sys.argv[-1]))
N = int(cmdlinearg("n"))
print(N)
