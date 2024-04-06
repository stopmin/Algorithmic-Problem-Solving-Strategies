import sys
N, M = map(int,sys.stdin.readline().rstrip().split())

site = {}
for i in range(N):
    A,B = sys.stdin.readline().rstrip().split()
    site[A] = B


for _ in range(M):
    x = sys.stdin.readline().rstrip()
    print(site[x])