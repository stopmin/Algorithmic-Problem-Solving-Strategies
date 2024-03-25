N = int(input()) % (15 * 10**5)
dp = [0] * (N+1)
dp[0] = 0
dp[1] = 1
for i in range(2,N+1):
    dp[i] = (dp[i-2] + dp[i-1]) % 1000000
print(dp[N])