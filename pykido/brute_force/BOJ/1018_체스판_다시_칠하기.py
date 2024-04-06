import sys

# 0 입력값 받기
N, M = map(int, sys.stdin.readline().rstrip().split())
chess_lst = [[0] for i in range(N)]
for i in range(N):
  chess_lst[i] = sys.stdin.readline().rstrip()


# 1 8x8 체크판 만들기
w_8_lst = "WBWBWBWB" # 맨 왼쪽 위 칸이 흰색인 8x8 체스판
b_8_lst = "BWBWBWBW" # 맨 왼쪽 위 칸이 검은색인 8x8 체스판
w_lst = [[0] for i in range(8)]
b_lst = [[0] for i in range(8)]
for i in range(8):
  if i % 2 == 0:
    b_lst[i] = b_8_lst
    w_lst[i] = w_8_lst
  else:
    b_lst[i] = w_8_lst
    w_lst[i] = b_8_lst

# 2 비교하기
# (1) 흰색으로 시작하는 체스판의 경우 
count1 = N * M
for i in range(N - 7):
  for j in range(M - 7):
    count_1_new = 0 # 다시 칠할 정사각형의 수 
    for n in range(8):
      for m in range(8):
        if w_lst[n][m] != chess_lst[i+n][j+m]:
          count_1_new += 1
    if count_1_new < count1:
      count1 = count_1_new
    
# (2) 검은색으로 시작하는 체스판의 경우 
count2 = N * M
for i in range(N - 7):
  for j in range(M - 7):
    count_2_new = 0 # 다시 칠할 정사각형의 수 
    for n in range(8):
      for m in range(8):
        if b_lst[n][m] != chess_lst[i+n][j+m]:
          count_2_new += 1
    if count_2_new < count2:
      count2 = count_2_new


result = 0
if count2 > count1:
  result = count1
else:
  result = count2

print(result)
