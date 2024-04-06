import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
def dfs(graph,v,visited):
    visited[v] = True
    for i in graph[v]:
        if not visited[i]:
            dfs(graph,i,visited)

N, M = map(int,input().split())
graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]
ans = 0
for _ in range(M):
    A, B = map(int,input().split())
    graph[A].append(B)
    graph[B].append(A)
for i in range(1,N+1):
        if visited[i] == False:
            ans += 1
            dfs(graph,i,visited)
print(ans)