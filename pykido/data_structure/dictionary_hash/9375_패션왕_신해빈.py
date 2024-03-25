import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T):
  n = int(sys.stdin.readline().rstrip())
  weardict = {}
  for j in range(n):
    wear = list(sys.stdin.readline().rstrip().split())
    if wear[1] in weardict:  # wear[1] : 옷 종류, wear[0] : 옷 이름
      weardict[wear[1]].append(wear[0])
    else:
      weardict[wear[1]] = [wear[0]]

  num = 1  # 각 종류마다 항목의 개수

  # 옷을 한 종류 이상 입어야하는데 모두 착용하지 않는 경우는 빼줘야함 !!!!!
  for i in weardict:
    num *= (len(weardict[i]) + 1)

  print(num - 1) # -1해주는 이유는 모든 의상을 착용하지 않는 경우를 빼주기 위해서 
