import sys  # 빠른 입력을 위해서
from collections import deque  # bfs를 사용하기 위해 queue를 불러들임

N, M, K, X = map(int, sys.stdin.readline().split())

# 입력 받기 및 초기 설정
map_lst = [[] for _ in range(N + 1)]
for _ in range(M):
  A, B = map(int, sys.stdin.readline().split())
  map_lst[A].append(B)

visited = [-1] * (N + 1)
visited[X] = 0

# 모든 도로의 거리가 1이므로 출발지 ~ 새로 방문하는 곳의 거리는 이전 도시까지의 거리 + 1이다.
queue = deque([X])
while queue:
  now = queue.popleft()
  for next in map_lst[now]:
    if visited[next] == -1:
      visited[next] = visited[now] + 1
      queue.append(next)

# check가 False라면 최단 거리가 K인 도시가 하나도 존재하지 않는다는 의미이다.
check = False
for i in range(1, N + 1):
  if visited[i] == K:
    print(i)
    check = True

if check == False:
  print(-1)
