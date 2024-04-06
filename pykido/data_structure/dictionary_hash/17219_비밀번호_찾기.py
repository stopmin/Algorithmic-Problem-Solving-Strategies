import sys

N, M = map(int, sys.stdin.readline().rstrip().split())
site_dict = {} # 파이썬에서 해시는 딕셔너리이다
for i in range(N) : 
  site, password = sys.stdin.readline().split()
  site_dict[site] = password 

for i in range(M) : 
  search_value = sys.stdin.readline().rstrip()
  print(site_dict[search_value])


