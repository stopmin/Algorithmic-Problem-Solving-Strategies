pay = 1000 - int(input())
coin_types = [500,100,50,10,5,1]
ans = 0
for coin in coin_types:
    ans += pay//coin
    pay %= coin
    
print(ans)