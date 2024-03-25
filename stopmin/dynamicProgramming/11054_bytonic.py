N = int(input())
array = list(map(int,input().split()))
dp = [0 for _ in range(N)]
for i in range(N):
    for j in range(i):
        if array[i] > array[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i] += 1

d = [0 for _ in range(N)]
for i in range(N-1,-1,-1):
    for j in range(N-1,i,-1):
        if array[i] > array[j] and d[i] < d[j]:
            d[i] = d[j]
    d[i] += 1

for i in range(len(dp)):
    dp[i] += d[i]
    dp[i] -= 1
    
print(max(dp))