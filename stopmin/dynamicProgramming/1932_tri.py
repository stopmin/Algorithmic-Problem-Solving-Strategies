N = int(input())
dp = [list(map(int,input().split())) for _ in range(N)]

if N == 1:
    print(dp[0][0])

else:
    for i in range(2):
        dp[1][i] = dp[1][i] + dp[0][0]

    for i in range(2,N):
        for j in range(i+1):
            if j == i:
                dp[i][j] = dp[i-1][j-1] + dp[i][j]
            elif j == 0:
                dp[i][j] = dp[i-1][j] + dp[i][j]
            else:
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + dp[i][j]
    print(max(dp[N-1]))