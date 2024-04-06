## 시간초과 났었던 풀이
N, K = map(int, input().split())

coin_lst = [0] * N
for i in range(N) :
  coin_lst[i] = int(input())
coin_lst.sort(reverse = True)

flag = 0
cnt = 0
while K != 0 : 
  if (K - coin_lst[flag]) == 0 : 
    cnt += 1
    break
  elif K - coin_lst[flag] < 0 :
    flag += 1
    continue
  else :
    K -= coin_lst[flag]
    cnt += 1

print(cnt)


## 옳은 풀이
N, K = map(int, input().split())

coin_lst = [0] * N
for i in range(N) :
  coin_lst[i] = int(input())
coin_lst.sort(reverse = True)

cnt = 0
for coin in coin_lst : 
  cnt += K // coin
  K %= coin

print(cnt)
