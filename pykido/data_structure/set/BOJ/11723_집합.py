# [자료형 중 집합에 관한 문제] 

import sys

# 0. 입력 받기
n = int(sys.stdin.readline().rstrip())
S = set() # 공집합 

# 1. 구현하기 
for i in range(n):
  command = sys.stdin.readline().rstrip()
 
  if command[0:3] == "add": 
    S.add(int(command[4])) # 집합에 원소 추가하기 
  elif command[0:6] == "remove" and (int(command[7]) in S):
    S.remove(int(command[7])) # 집합에 있는 원소 삭제하기 
  elif command[0:5] == "check":
    if int(command[6]) in S: # 집합에 원소 있는지 확인하기 
      print(1)
    else:
      print(0)
  elif command[0:6] == "toggle":
    if int(command[7]) in S:
      S.remove(int(command[7]))
    else:
      S.add(int(command[7]))
  elif command[0:3] == "all":
    S.clear() # 집합 비우기 
    # 집합에 여러 원소 추가하기 
    S.update(
      [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
  elif command[0:5] == "empty":
    S.clear()
