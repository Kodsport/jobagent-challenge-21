#!/usr/bin/env python3

def numberOfSteps(unordered_list, n):
    visited = [0 for _ in range(n)]
    steps = 0
    for i in range(n):
        node = i
        if not visited[node]:
            visited[node] = 1
            while not visited[unordered_list[node]]:
                steps += 1
                node = unordered_list[node]
                visited[node] = 1
    return steps

n = int(input())
jobs = [0 for _ in range(n)]
for i in range(n):
    c, w = map(int, input().split())
    jobs[c-1] = w-1

print(numberOfSteps(jobs,n))