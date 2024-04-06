import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
def dfs(x,y):
    if x<=-1 or x>=n or y<=-1 or y>= m:
        return False
    if graph[x][y] == 0:
        graph[x][y] = 1
        dfs(x-1,y)
        dfs(x,y-1)
        dfs(x+1,y)
        dfs(x,y+1)
        return True
    return False

for _ in range(int(input())):
    n,m,k = map(int,input().split())
    graph = []
    for i in range(n):
        graph.append([1 for _ in range(m)])

    for _ in range(k):
        a, b = map(int,input().split())
        graph[a][b] = 0



    result = 0
    for i in range(n):
        for j in range(m):
            if dfs(i,j) == True:
                result += 1
            
    print(result)
