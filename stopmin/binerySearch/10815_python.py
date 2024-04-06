import sys
N = int(input())
A = set(map(int,sys.stdin.readline().split()))
M = int(input())
B = list(map(int,sys.stdin.readline().split()))
ans = list()
for i in B:
    if i in A:
        ans.append(1)
    else: ans.append(0)

print(*ans)