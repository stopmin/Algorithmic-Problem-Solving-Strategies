# [사전형을 이용한 문제]

import sys

# 0. 입력 받기
N, M = map(int, sys.stdin.readline().rstrip().split())
pokemon_dict = {} # 포켓몬 도감

for i in range(1,N + 1) :  # 입력 받기 
  pokemon = sys.stdin.readline().rstrip()
  pokemon_dict[i] = pokemon
  pokemon_dict[pokemon] = i 

# 1. 구현하기 
for i in range(M):
  quest = sys.stdin.readline().rstrip()
  if quest.isdigit(): # 만약 숫자라면 
    quest = int(quest)
    print(pokemon_dict[quest])
  else : 
    print(pokemon_dict[quest])
    
