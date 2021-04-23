import sys
import random

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=", 1)[1]

random.seed(int(sys.argv[-1]))
N = int(cmdlinearg("n"))

print(N, N//2)
S = ['a' if i%2 else 'b' for i in range(N)]
S[0] = 'c'
S[N // 2] = 'c'
print(''.join(S))
