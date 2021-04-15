#!/usr/bin/env python3

n = int(input())

jobs = sorted(list(set(map(int,input().split()))))
para = 0
tim = 0

for job in jobs:
    if job >= tim:
        para += 4
        tim = job + 4*10**5

print(para)
