from collections import deque

n,m = map(int,input().split())
graph = [list(map(int,input().split())) for _  in range(n)]

dx = [ -1, 1, 0, 0]
dy = [ 0, 0, -1, 1]

def bfs(graph,x,y):
    queue = deque()
    queue.append((x,y))
    graph[x][y] = 0
    count = 1

    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny <0 or nx >= n or ny >= m:
                continue
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx,ny))
                count += 1
    return count

paint = []
for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            paint.append(bfs(graph,i,j))

if len(paint) == 0:
    print(len(paint))
    print(0)

else:
    print(len(paint))
    print(max(paint))