import sys
N, M = map(int,sys.stdin.readline().rstrip().split())
A = set()
for _ in range(N):
    A.add(sys.stdin.readline().rstrip())
B = set()
for _ in range(M):
    B.add(sys.stdin.readline().rstrip())
ans = sorted(list(A&B))
print(len(ans))
for w in ans:
    print(w)