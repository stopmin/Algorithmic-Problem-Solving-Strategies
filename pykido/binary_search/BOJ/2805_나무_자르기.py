# [전형적인 이분 탐색 문제] (pypy로 제출하였음)

import sys

# 0. 입력 받기
N, M = map(int, sys.stdin.readline().rstrip().split())
height_lst = list(map(int, sys.stdin.readline().rstrip().split()))

# 1. 이분 탐색을 통해 절단기에 설정할 수 있는 높이의 최댓값 찾기
start = 0
end = max(height_lst)

while start <= end:
  mid = (start + end) // 2
  val = 0  # 잘린 나무들의 값
  for i in range(len(height_lst)):  # 설정한 높이대로 다 잘라본다
    diff = height_lst[i] - mid
    if diff > 0:
      val += diff

  if val >= M:  # 높이의 최댓값 찾기!!!!
    start = mid + 1
  else:
    end = mid - 1

print(end)
