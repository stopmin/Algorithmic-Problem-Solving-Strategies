import sys  # 빠른 입력을 위해서
import copy
from collections import deque  # bfs를 사용하기 위해 queue를 불러들임

# 입력 받기
N, M = map(int, sys.stdin.readline().split())
map_lst = []  # map_lst에 지도 정보가 저장됨
result = 0  # 최종결과값
for i in range(N):
  map_lst.append(list(map(int, sys.stdin.readline().split())))  # 연구소 지도


# bfs 구현
def bfs():
  global result
  queue = deque()
  graph = copy.deepcopy(map_lst)  # deepcopy를 통해

  # 바이러스들을 전부 queue에 추가한다.
  for i in range(N):
    for j in range(M):
      if graph[i][j] == 2:
        queue.append([i, j])

  while queue:
    now = queue.popleft()
    # 현재 위치로부터 상하좌우 확인
    for i in range(4):
      next_x = now[0] + steps_x[i]
      next_y = now[1] + steps_y[i]
      # 공간을 벗어나는 경우 제외시켜주기
      if next_x <= -1 or next_x >= N or next_y <= -1 or next_y >= M:
        continue
      # 전염 가능하면 바로 전염시키기
      if (graph[next_x][next_y] == 0):
        graph[next_x][next_y] = 2
        queue.append([next_x, next_y])

  # 감염되지 않은 곳을 확인
  count = 0
  for i in range(N):
    for j in range(M):
      if graph[i][j] == 0:
        count += 1
  result = max(result, count)  # 감염되지 않은 곳의 수가 최대인 경우를 파악하는 것이기때문


# 벽 만들기
def make_wall(count):
  if count == 3:  # count가 3이라면 벽을 3개 다 설치한 경우이기에 bfs 실행
    bfs()
    return  # bfs 과정이 끝나면 return

  for i in range(N):
    for j in range(M):
      if map_lst[i][j] == 0:
        map_lst[i][j] = 1  # 백트래킹
        make_wall(count + 1)
        map_lst[i][j] = 0


steps_x = [0, 0, -1, 1]  # 상,하,좌,우
steps_y = [1, -1, 0, 0]

make_wall(0)
print(result)
