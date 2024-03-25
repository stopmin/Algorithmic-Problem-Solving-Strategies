# 내 풀이
N = int(input())

move_plan_lst = list(input().split())
move_square_lst = [[0] * N for _ in range(N)]

x = 1
y = 1
for i in range(len(move_plan_lst)) :
  if move_plan_lst[i] == 'R' and y < N : 
      y += 1
  elif move_plan_lst[i] == 'L' and y > 1 : 
      y -= 1
  elif move_plan_lst[i] == 'U' and x > 1 : 
      x -= 1 
  elif move_plan_lst[i] == 'D' and x < N : 
      x += 1

print(x,y)



# 동빈좌 풀이 
# N을 입력 받기 
n = int(input())
x, y = 1, 1
plans = input().split()

# L, R, U, D에 따른 이동 방향
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ['L', 'R', 'U', 'D']

# 이동 계획을 하나씩 확인
for plan in plans : 
  # 이동 후 좌표 구하기
  for i in range(len(move_types)) :
    if plan == move_types[i] : 
      nx = x + dx[i]
      ny = y + dy[i]
  # 공간을 벗어나는 경우 무시
  if nx < 1 or ny <1 or nx > n or ny > n  :
      continue
  # 이동 수행
  x, y = nx, ny

print(nx,ny)
