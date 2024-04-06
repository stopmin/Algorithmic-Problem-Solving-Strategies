# 빠른 입력 받기 
import sys
N = int(sys.stdin.readline().rstrip())
N_lst = list(map(int, sys.stdin.readline().rstrip().split()))
M = int(sys.stdin.readline().rstrip())
M_lst = list(map(int, sys.stdin.readline().rstrip().split()))

# 이진 탐색 함수 (반복문 이용)
def binary_search(array, target, start, end) : 
  while start <= end : 
    mid = (start + end) // 2
    if target == array[mid] : 
      return mid
    elif target < array[mid] : 
      end = mid - 1
    else : 
      start = mid + 1
  return None 

# N_lst 정렬해주기 
N_lst.sort()

# M_lst의 원소들을 살펴보면서 존재한다면 'yes', 존재하지 않는다면 'no' 출력 
for x in M_lst : 
  result = binary_search(N_lst, x, 0, N - 1)  
  if result == None : 
    print("no", end = " ")
  else :
    print("yes", end = " ")
