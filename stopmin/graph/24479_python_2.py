import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline

def dfs(start):
    global cnt
    V[start] = cnt
    E[start].sort()

    for i in E[start]:
        if not V[i]:
            cnt += 1
            dfs(i)

n,m,r = map(int,input().split())
E = [[] for _ in range(n+1)]
V = [0]*(n+1)

for i in range(m):
    u, v = map(int,input().split())
    E[u].append(v)
    E[v].append(u)

cnt = 1
dfs(r)
for i in range(1,n+1):
    print(V[i])