# 1. 빠른 입력 받기
import sys 
N = int(sys.stdin.readline().rstrip())
array = list(map(int, sys.stdin.readline().rstrip().split()))

# 2. 이진 탐색을 통해 고정점 찾기 
result = - 1
start = 0 
end = N - 1
while start <= end : 
  mid = (start + end) // 2
  if mid == array[mid] : 
    result = mid
    break
  elif array[mid] < mid : 
    start = mid + 1
  else : 
    end = mid - 1

print(result)
