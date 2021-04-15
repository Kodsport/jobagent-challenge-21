#!/usr/bin/env python3

n = int(input())

jobs = sorted(list(set(map(int,input().split())))) + [10**18]
para = 0

for ind, job in enumerate(jobs[:-1]):
    best_lax = 0
    for lax in [0,2,3,4]:
        if jobs[ind+1] <= job + lax*10**5:
            best_lax = lax
    para += best_lax

print(para)
