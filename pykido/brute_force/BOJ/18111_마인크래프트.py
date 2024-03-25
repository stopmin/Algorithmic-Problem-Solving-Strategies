# [브루트포스 알고리즘] pypy로 제출하였음

import sys

# 0. 입력 받기
N, M, B = map(int, sys.stdin.readline().rstrip().split())
ground_lst = [[0] for i in range(N)]
for i in range(N):
  # 2차원 배열에 입력 받기
  ground_lst[i] = list(map(int, sys.stdin.readline().rstrip().split()))

# 1. 구현하기 by 브루트포스 알고리즘
sum_block_lst = sum(ground_lst, [])  # 2차원 리스트를 1차원 리스트로 바꾸는 과정
lowest_block = min(sum_block_lst)  # 가장 높은 땅의 높이
highest_block = max(sum_block_lst)  # 가장 낮은 땅의 높이
min_time = (highest_block - lowest_block) * 2 * N * M  # 땅 고르는 최소 시간
max_height = highest_block  # 땅 골랐을 때의 최대 높이
sum_blocks = sum(sum_block_lst)  # 모든 땅 높이들의 합

for h in range(highest_block, lowest_block - 1, -1):  # 최대 높이에서 최소 높이까지 탐색
  if sum_blocks + B >= h * N * M:  # 모든 블록 높이의 합과 블록의 합으로 h 높이만큼 채울 수 있어야 쌓을 수 있음
    time = 0
    for block in sum_block_lst:
      diff = h - block
      if diff > 0:  # 만약 탐색하는 높이 h보다 현재 높이가 크면 덜어내야함
        time += diff
      elif diff < 0:  # 만약 탐색하는 높이 h보다 현재 높이가 작ㅇ면 쌓아야함
        time += 2 * (-diff)
    if time < min_time:  # 땅을 고르는 최소 시간과 최대 높이 구하기
      min_time = time
      max_height = h

print(min_time, max_height)
