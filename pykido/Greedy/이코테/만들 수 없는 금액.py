### 내 풀이 
import sys
N = int(sys.stdin.readline().rstrip())
coin_lst = list(map(int, sys.stdin.readline().rstrip().split()))

result = 1
coin_lst.sort(reverse = True)
check = True
while True : 
  tmp = result
  for i in range(0, len(coin_lst)) : 
    if tmp - coin_lst[i] >= 0 : 
      tmp -= coin_lst[i]
      if tmp == 0 : 
        result += 1
        break
    if i == len(coin_lst) - 1 : 
      check = False
  if check == False : 
    break

print(result)


### 동빈좌 풀이
n = int(input())
data = list(map(int, input().split()))
data.sort()

target = 1
for x in data:
  # 만들 수 없는 금액을 찾았을 때 반복 종료
  if target < x:
    break
  target += x

# 만들 수 없는 금액 출력
print(target)
