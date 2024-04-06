import sys
N, M, R = map(int,sys.stdin.readline().rstrip().split())
graph = [list() for _ in range(N+1)]

for _ in range(M):
    A, B = map(int,sys.stdin.readline().rstrip().split())
    graph[A].append(B)
    graph[B].append(A)

for i in range(N+1):
    graph[i] = sorted(graph[i])

visited = [False]*(N+1)

def dfs(graph,v,visited):
    visited[v] = True
    print(v)

    for i in graph[v]:
        if not visited[i]:
            dfs(graph,i,visited)



dfs(graph,R,visited)