import sys
N, M = map(int, sys.stdin.readline().rstrip().split())
h_lst = list(map(int, sys.stdin.readline().rstrip().split()))

# 1. 주어진 조건을 만족하는 가장 큰값을 찾으라는 최적화 문제
# -> 이진 탐색을 반복하며 결정 짓는 결정 문제로 바꾸어 해결하기
start = 0
end = max(h_lst)
result = 0

while start <= end:
  mid = (start + end) // 2
  total = 0
  # 떡볶이 떡 자르기
  for x in h_lst:
    if x > mid:
      total += x - mid
  # 자른 떡볶이 떡의 길이가 손님이 요청한 길이보다
  if total < M:  # 작으면 왼쪽 부분 탐색
    end = mid - 1
  else:          # 크면 오른쪽 부분 탐색
    result = mid  # 갱신해주기 
    start = mid + 1

print(result)
