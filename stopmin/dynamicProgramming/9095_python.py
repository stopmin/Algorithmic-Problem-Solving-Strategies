import sys
input = sys.stdin.readline

cnt = int(input())

def ans(n):
    if n<=3:
        dp = [1,2,4]
        return dp[n-1]
    elif n>3:
        dp = [1,2,4] + [0]*(n-3)
        for i in range(3,n):
            dp[i] = dp[i-3]+dp[i-2]+dp[i-1]
        return dp[-1]

for _ in range(cnt):
    print(ans(int(input())))