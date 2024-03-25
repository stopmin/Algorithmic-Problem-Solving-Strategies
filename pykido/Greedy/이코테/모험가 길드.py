### 내 풀이 
# 입력 받기
import sys

N = int(sys.stdin.readline().rstrip())
traveler_lst = list(map(int, sys.stdin.readline().rstrip().split()))
traveler_lst.sort(reverse=True)

# 그리디 구현
result = 0  # 결과값
i = 0
while i < N:
  if traveler_lst[i] <= N - i:  # 모험가 공포도가 남아있는 사람들보다 작거나 같으면 그룹 가능
    result += 1
    i += traveler_lst[i]
  else:
    i += 1

print(result)


### 동빈좌 풀이 
n = int(input())
data = list(map(int, input().split()))
data.sort()

result = 0 # 총 그룹의 수 
count = 0 # 현재 그룹에 포함된 모험가의 수 

for i in data : # 공포도를 낮은 것부터 하나씩 확인하며 
  count += 1 # 현재 그룹에 해당 모험가를 포함시키기
  if count >= i : # 현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면, 그룹 결성
    result += 1  # 총 그룹의 수 증가시키기
    count = 0 # 현재 그룹에 포함된 모험가의 수 초기화

print(result)
