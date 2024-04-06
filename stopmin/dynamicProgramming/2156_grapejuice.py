N = int(input())
grape = [0]

for _ in range(N):
    grape.append(int(input()))


if N == 1:
    print(grape[1])

else:
    dp = [0]*(N+1)
    dp[0] = grape[0]
    dp[1] = grape[0] + grape[1]
    dp[2] = max(grape[0] + grape[2], grape[1] + grape[2])
    for i in range(3,N+1):
        dp[i] = max(dp[i-2] + grape[i],dp[i-3] + grape[i-1] + grape[i])
        dp[i] = max(dp[i-1], dp[i])
    print(max(dp))