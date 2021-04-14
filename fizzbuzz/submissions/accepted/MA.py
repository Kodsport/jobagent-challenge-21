#!/usr/bin/env python3

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

n, m = map(int, input().split())
corr_seq = correct_seq(m)

best = []
minerr = 10**9
for i in range(n):
    inp = input().split()
    err = 0
    for j in range(m):
        if corr_seq[j] != inp[j]:
            err += 1
    
    if err < minerr:
        minerr = err
        best = str(i+1)

print(best)
