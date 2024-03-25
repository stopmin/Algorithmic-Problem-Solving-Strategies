import sys
from collections import deque
from queue import Queue

N, M, V = map(int,sys.stdin.readline().rstrip().split())

graph = [[] for _ in range(N+1)]

for i in range(M):
    a, b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

for j in graph:
    j.sort()


def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


visited_dfs = [False]*(N+1)
visited_bfs = [False]*(N+1)

dfs(graph,V,visited_dfs)
print()
bfs(graph,V,visited_bfs)
