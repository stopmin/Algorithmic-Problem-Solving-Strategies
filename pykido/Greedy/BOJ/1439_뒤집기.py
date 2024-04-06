### 내 풀이
# 1. 입력 받기 
import sys
num_lst = list(map(int, sys.stdin.readline().rstrip()))

# 2. 그리디 구현 
flag = num_lst[0] # flag로 result_lst에 연속된 한 개 이상의 0, 1이 몇 개인지 구하기 
result_lst = [0, 0]
result_lst[flag] += 1
for i in range(0, len(num_lst)):
  if num_lst[i] != flag:
    flag = 0 if num_lst[i] == 0 else 1
    result_lst[flag] += 1

# 3. 출력 
print(min(result_lst))


### 동빈좌 풀이 
data = input()
count0 = 0 # 전부 0으로 바꾸는 경우 
count1 = 0 # 전부 1로 바꾸는 경우

# 첫 번째 원소에 대해서 처리
if data[0] == '1' : 
  count0 += 1
else : 
  count1 += 1

# 두 번째 원소부터 모든 원소를 확인하며
for i in range(len(data) - 1) :
  if data[i] != data[i + 1] :
    # 다음 수부터 1로 바뀌는 경우
    if data[i + 1] == '1' :
      count0 += 1
    # 다음 수에서 0으로 바뀌는 경우
    else : 
      count1 += 1

print(min(count0, count1))
