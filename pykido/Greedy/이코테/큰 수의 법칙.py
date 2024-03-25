1. 내 풀이 

# 입력 받기 
N, M, K = map(int,input().split())

num_lst = list(map(int,input().split()))

# 내림차순으로 정렬하기 
num_lst.sort(reverse= True)

# 그리디 알고리즘 
flag = 0 
cnt = 0
result = 0 
for i in range(M) :
  if cnt == K :
    flag = 1
    result += num_lst[flag]
    flag = 0
    cnt = 0 
  else : 
    result += num_lst[flag]
    cnt += 1 

print(result)






2. 동빈좌 풀이 

(1)
# N, M, K를 공백으로 구분하여 입력 받기
n, m, k = map(int,input().split())

# N개의 수를 공백으로 구분하여 입력 받기 
data = list(map(int,input().split()))

data.sort() # 입력 받은 수들 정렬하기
first = data[n - 1] # 가장 큰 수 
second = data[n - 2] # 두번째로 큰 수 

result = 0 

while True : 
  for i in range(k) : # 가장 큰 수를 K번 더하기
    if m == 0 : # m이 0이라면 반복문 탈출
      break
    result += first
    m -= 1  # 더할 때마다 1씩 빼기 
  if m == 0 : # m이 0이라면 반복문 탈출
    break
  result += second # 두번째로 큰 수를 한 번 더하기
  m -= 1 # 더할 때마다 1씩 빼기

print(result) # 최종 답안 출력

(2) 
# N, M, K를 공백으로 구분하여 입력받기 
n, m, k = map(int,input().split())

# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int,input().split()))

data.sort() # 입력 받은 수 정렬
first = data[n - 1] # 가장 큰 수 
second = data[n - 2] # 두번째로 큰 수 

# 가장 큰 수 가 더해지는 횟수 계산
count = int(m / (k + 1)) * k
count += m % (k + 1)

result = 0 
result += (count) * first # 가장 큰 수 더하기
result += (m - count) * second # 두 번째로 큰 수 더하기

print(result)  # 최종 답안 출력 
