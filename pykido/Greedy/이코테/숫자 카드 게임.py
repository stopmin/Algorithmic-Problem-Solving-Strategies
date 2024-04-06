## 내 풀이 

# 입력 받기 
N, M = map(int,input().split())

num_card_lst = [0] * N 
min_card_lst = [0] * N 
for i in range(N) :
  num_lst = list(map(int,input().split()))
  num_card_lst[i] = num_lst 
  min_card_lst[i] = min(num_lst)

print(max(min_card_lst))





## 동빈좌 풀이 - 1 min() 함수를 이용

# N, M을 공백으로 구분하여 입력 받기 
n, m = map(int,input().split())

result = 0 
# 한 줄씩 입력받아 확인
for i in range(n) : 
  data = list(map(int,input().split()))
  # 현재 줄에서 '가장 작은 수' 찾기 
  min_value = min(data)
  # '가장 작은 수'들 중에서 가장 큰 수 찾기
  result = max(result, min_value)

print(result)  # 최종 답안 출력 






## 동빈좌 풀이 - 2 2중 반복문 구조 이용 

# N, M을 공백으로 구분하여 입력 받기 
n, m = map(int,input().split())

result = 0 
# 한 줄씩 입력받아 확인
for i in range(n) : 
  data = list(map(int,input().split()))
  # 현재 줄에서 '가장 작은 수' 찾기 
  min_value = 10001
  for a in data : 
    min_value = min(min_value, a)
  # '가장 작은 수'들 중에서 가장 큰 수 찾기
  result = max(result, min_value)

print(result)  # 최종 답안 출력 
