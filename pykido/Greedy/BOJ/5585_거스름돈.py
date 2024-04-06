# 내 풀이 
N = 1000 - int(input())

coin_lst = [500,100,50,10,5,1]
i = 0 
coin_cnt = 0 

while N != 0 : 
  if N // coin_lst[i] > 0 : 
    coin_cnt += 1
    N -= coin_lst[i]
  else : 
    i += 1

print(coin_cnt)

# 이코테 나동빈식 풀이 
N = 1000 - int(input())

coin_lst = [500,100,50,10,5,1]
coin_cnt = 0 

for coin in coin_lst : 
  coin_cnt += N // coin 
  N %= coin

print(coin_cnt)
