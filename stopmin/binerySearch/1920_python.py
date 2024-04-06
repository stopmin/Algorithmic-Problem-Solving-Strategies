import sys
N = int(input())
A = set(map(int,sys.stdin.readline().split()))
M = int(input())
B = list(map(int,sys.stdin.readline().split()))

for i in B:
    if i in A:
        print(1)
    else: print(0)
