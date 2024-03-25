N = int(input())
array = []
dp = []

for i in range(N):
    array.append(list(map(int,input().split())))
    dp.append(array[i][1])

for i in range(0,N):
    if i+array[i][0]+1>N+1:
        dp[i] = 0
        continue
    elif i + array[i][0]< N:
        dp[i+array[i][0]] = max(dp[i+array[i][0]],dp[i]+array[i+array[i][0]][1])
print(max(dp))
