# [스택 문제] 

import sys
import copy

# 0. 입력 받기
n = int(sys.stdin.readline().rstrip())
seq_lst = [0] * n  # 입력된 수열
for i in range(n):
  seq_lst[i] = int(sys.stdin.readline().rstrip())
num_lst = copy.deepcopy(seq_lst)  # 스택에 하나하나 push할 수열
num_lst.sort()

# 1. 구현하기
flag = 0
stack = []  # 스택
result = []  # +, - 결과값

# 일단 기본 전제는 스택에 1~n까지의 수열을 넣으며 스택의 마지막값인 stack[-1]과 입력된 수열을 비교하고 입력된 수열을 만들고자하는 연산을 수행한다.
for i in range(1, n + 1):
  result.append('+')
  stack.append(i)  # 일단 push
  while True:
    if len(stack) >= 1 and stack[-1] == seq_lst[flag]:  # 같으면 입력된 수열 만족!
      result.append('-')
      stack.pop()
      flag += 1
      if flag == n:
        break
      else:
        continue
    else:
      break

# 2. 출력하기
if flag == n:
  for i in range(len(result)):
    print(result[i])
else:
  print("NO")
