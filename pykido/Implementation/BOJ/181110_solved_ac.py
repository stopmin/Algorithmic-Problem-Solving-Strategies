import sys

# 파이썬의 내장함수 round는 기본적으로 사사오입이 아닌 자연과학이나 유효숫자에서 많이 사용되는 오사오입의 방식을 택한다. 
# 오사오입이란 반올림할 자릿수가 5일 때, 그 5의 앞자리 수가 홀수라면 올림, 짝수라면 내림하는 방식이다.
# 따라서 사사오입으로 반올림하는 함수를 따로 구현해주어야한다. 
def my_round_45(num):
  if num - int(num) >= 0.5:
    return int(num) + 1
  else:
    return int(num)

# 0. 입력 받기 
n = int(sys.stdin.readline().rstrip())

# 1. 구현하기 
if n == 0:
  print(0)
else:
  num_lst = [0] * n 
  for i in range(n):
    num_lst[i] = int(sys.stdin.readline().rstrip())

  tm_range = my_round_45(n * 0.15) # 15%의 범위 
  num_lst.sort() # 오름차순으로 정렬하기 

  # 15%의 범위가 0이 아닌 경우는 슬라이싱하자!
  if tm_range == 0:
    print(my_round_45(sum(num_lst) / len(num_lst))) 
  else:
    print(my_round_45(sum(num_lst[tm_range:-tm_range]) / len(num_lst[tm_range:-tm_range])))
