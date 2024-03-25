## 내 풀이
where = list(input())
column = ord(where[0]) - 96 # 열
row = int(where[1])         # 행 

cnt = 0

## 최대 8개 가능 
# 왼쪽으로(수평) 두 칸 가능
if column >= 3 : 
  if row >= 2 : # 왼쪽 위  
    cnt += 1
  if row <= 7 : # 왼쪽 아래 
    cnt += 1

# 오른쪽으로(수평) 두 칸 가능
if column <= 6 : 
  if row >= 2 : # 오른쪽 위
    cnt += 1
  if row <= 7 : # 오른쪽 아래
    cnt += 1

# 위로(수직) 두 칸 가능
if row >= 3 : 
  if column >= 2 : # 왼쪽 위 
    cnt += 1
  if column <= 7 : # 오른쪽 위 
    cnt += 1

# 아래로(수직) 두 칸 가능
if row <= 6 : 
  if column >= 2 : # 왼쪽 아래 
    cnt += 1
  if column <= 7 : # 오른쪽 아래 
    cnt += 1

print(cnt)



## 동빈좌 풀이 
# 현재 나이트 위치 입력 받기
input_data = input()
row = int(input_data[1]) # 행
column = int(ord(input_data[0])) - int(ord('a')) + 1

# 나이트가 이동할 수 있는 8가지 방향 정의 
steps = [(-2, -1), (-1, -2), (1, -2), (2, - 1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

# 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
result = 0
for step in steps : 
  # 이동하고자 하는 위치 확인
  next_row = row + step[0]
  next_column = column + step[1]
  # 해당 위치로 이동이 가능하다면 카운트 증가
  if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8 : 
    result += 1

print(result)
