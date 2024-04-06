### 내 풀이 
import sys
Num_lst = list(map(int, sys.stdin.readline().rstrip()))

result = Num_lst[0]
for i in range(1, len(Num_lst)) : 
  if result * Num_lst[i] > (result + Num_lst[i]) : 
    result *= Num_lst[i]
  else : 
    result += Num_lst[i]

print(result)



### 동빈좌 풀이
data = input()

# 첫 번째 문자를 숫자로 변경하여 대입
result = int(data[0])

for i in range(1, len(data)) :
  # 두 수 중에서 하나라도 '0' 혹은 '1'인 경우, 곱하기보다는 더하기 수행
  num = int(data[i])
  if num <= 1 or result <= 1 : 
    result += num
  else : 
    result += num

print(result)
