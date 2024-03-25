import sys  # 빠른 입력을 위해서
from collections import deque  # bfs를 사용하기 위해 queue를 불러들임

# 입력 받기
N, M = map(int, sys.stdin.readline().split())
map_lst = []
for i in range(N):
  map_lst.append(list(map(int, sys.stdin.readline().rstrip())))

# steps를 통해 이후의 스텝에서 괴물이 없는지 확인 가능
steps_x = [0, 0, -1, 1]  # 상, 하, 좌, 우
steps_y = [1, -1, 0, 0]
queue = deque()
queue.append([0, 0])  # 시작은 (1,1)이므로!!

# bfs
while queue:
  now = queue.popleft()

  # 현재 위치로부터 상하좌우 확인
  for i in range(4):
    next_x = now[0] + steps_x[i]
    next_y = now[1] + steps_y[i]
    # 공간을 벗어나는 경우 제외시켜주기 
    if next_x <= -1 or next_x >= N or next_y <= -1 or next_y >= M:
      continue
    # 해당 지점을 처음으로 방문하는 경우 최단 거리 기록
    if (map_lst[next_x][next_y] == 1):
      map_lst[next_x][next_y] += map_lst[now[0]][now[1]]
      queue.append([next_x, next_y])

print(map_lst[N - 1][M - 1])

# 5 6
# 101010
# 111111
# 000001
# 111111
# 111111
