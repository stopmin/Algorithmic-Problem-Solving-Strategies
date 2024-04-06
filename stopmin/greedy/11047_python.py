import sys

N, K = map(int,sys.stdin.readline().rstrip().split())
coin_type = list()
for _ in range(N):
    coin_type.append(int(sys.stdin.readline().rstrip()))

coin_type.sort()
coin_type.reverse()
ans = 0
for coin in coin_type:
    tmp = K//coin
    ans += tmp
    K = K%coin

print(ans)

