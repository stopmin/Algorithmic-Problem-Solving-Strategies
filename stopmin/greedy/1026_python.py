import sys
S = int(input())
A = list(map(int,sys.stdin.readline().split()))
B = list(map(int,sys.stdin.readline().split()))

A = sorted(A)
B = sorted(B)
B.reverse()

ans = 0

for i in range(S):
    ans += A[i]*B[i]

print(ans)