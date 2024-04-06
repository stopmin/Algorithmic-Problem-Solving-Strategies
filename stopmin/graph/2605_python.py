import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

com_num = int(input())
network = int(input())

graph = [list() for _ in range(com_num+1)]
visited = [False]*(com_num+1)

for _ in range(network):
    A, B = map(int,input().split())
    graph[A].append(B)
    graph[B].append(A)

ans = 0

def dfs(start):
    global ans
    visited[start] = True
    for i in graph[start]:
        if not visited[i]:
            ans += 1
            dfs(i)
dfs(1)
print(ans)
