## 나의 풀이
# 입력 받기
N, M = map(int, input().split())
A, B, d = map(int, input().split())  # A : 북~거리, B : 서~거리, d : 방향

map_lst = [0] * N
for i in range(N):
  map_lst[i] = list(map(int, input().split()))

# 시뮬레이션 짜기
steps = [[0, -1], [1, 0], [0, 1], [-1, 0]]
pos = [A, B]  # 처음 위치
map_lst[pos[0]][pos[1]] = 1  # 처음 위치는 당연히 가본 곳이기에 1
cnt = 0  # 방향전환한 횟수
result = 1  # 방문한 칸의 수

while True:
  d = d % 4

  # 바라보는 방향에서 왼쪽으로의 이동이 유효한지 확인하자!!
  next_pos = [pos[0] + steps[d][0], pos[1] + steps[d][1]]
  if map_lst[next_pos[0]][next_pos[1]] == 1:
    d += 1
    cnt += 1
    if cnt == 4:  # 사면이 1인 경우 움직임을 멈춘다
      break
  else:
    pos = next_pos
    result += 1
    d += 1
    map_lst[pos[0]][pos[1]] = 1
    cnt = 0

print(result)






## 동빈좌 풀이
# N, M을 공백으로 구분하여 입력 받기
n, m = map(int, input().split())

# 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
d = [[0] * m for _ in range(n)]
# 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
x, y, direction = map(int, input().split())
d[x][y] = 1 # 현재 좌표 방문 처리

# 전체 맵 정보를 입력 받기
array = []
for i in range(n) :
  array.append(list(map(int,input().split())))

# 북, 동, 남, 서 방향 정의
dx = [-1,0,1,0]
dy = [0,1,0,-1]

# 왼쪽으로 회전
def turn_left() : 
  global direction 
  direction -= 1
  if direction == -1 : 
    direction = 3

# 시뮬레이션 시작
count = 1
turn_time = 0
while True :
    # 왼쪽으로 회전 
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    # 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
    if d[nx][ny] == 0 and array[nx][ny] == 0 :
      d[nx][ny] = 1
      x = nx 
      y = ny
      count += 1
      turn_time = 0
      continue 
    # 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
    else :
      turn_time += 1
    # 네 방향 모두 갈 수 없는 경우
    if turn_time == 4 : 
      nx = x - dx[direction]
      ny = y - dy[direction]
      # 뒤로 갈 수 있다면 이동하기 
      if array[nx][ny] == 0 :
        x = nx
        y = ny
      # 뒤가 바다로 막혀있는 경우 
      else : 
        break 
      turn_time = 0

# 정답 출력
print(count)
