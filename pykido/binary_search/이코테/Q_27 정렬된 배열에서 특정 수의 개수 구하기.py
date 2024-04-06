# 1. 빠른 입력 받기
import sys
N, x = map(int, sys.stdin.readline().rstrip().split())
N_lst = list(map(int, sys.stdin.readline().rstrip().split()))


# 2. 이진 탐색 함수 구축 - 처음, 끝 찾기
#### 수열에서 x의 첫 등장 위치 찾기
def binary_search_start(array, target, start, end):
  while start <= end:
    mid = (start + end) // 2
    # 타겟이랑 array[mid]랑 같더라도 첫 등장 위치여야함을 기억하자
    if target == array[mid] and (mid == 0 or (target > array[mid - 1])):
      return mid
    # 왼쪽으로 계속 탐색해주는 것이 유리함
    elif target > array[mid]:
      start = mid + 1
    else:
      end = mid - 1
  return 0

### 수열에서 x의 마지막 등장 위치 찾기
def binary_search_end(array, target, start, end):
  while start <= end:
    mid = (start + end) // 2
    # 타겟이랑 array[mid]랑 같더라도 마지막 등장 위치여야함을 기억하자
    if target == array[mid] and ((mid == N - 1) or (target < array[mid + 1])):
      return mid
    # 오른쪽으로 게속 탐색해주는 것이 유리함
    elif target < array[mid]:
      end = mid - 1
    else:
      start = mid + 1
  return 0

start = binary_search_start(N_lst, x, 0, N - 1)
end = binary_search_end(N_lst, x, 0, N - 1)
result = end - start
if result == 0:  # 값이 x인 원소가 하나도 없다면
  print(-1)
else:
  print(result)

