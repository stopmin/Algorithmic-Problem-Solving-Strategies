import sys

# 0 입력값 받기
K, N = map(int, sys.stdin.readline().rstrip().split())
K_lst = [0] * K # 랜선들
for i in range(K):
  K_lst[i] = int(sys.stdin.readline().rstrip())

# 1. x값 정의하기 
## K_lst에 있는 모든 값들을 특정 값으로 나눈 값이 N값 이상이어야하기에 기본적으로 특정값이 어떤 값 이하인지 알 수 있다. 
sum_K = sum(K_lst)
x = sum_K // N

# 2. 이분 탐색 활용하여 랜서의 최대 길이 구하기 
start = 1
end = x
while start <= end:
  mid = (start + end) // 2
  
  num = 0 # num : 자른 랜선의 갯수
  for i in range(K): 
    num += K_lst[i] // mid # 자르는중...

  if num >= N:
    start = mid + 1
  else:
    end = mid - 1

print(end)
