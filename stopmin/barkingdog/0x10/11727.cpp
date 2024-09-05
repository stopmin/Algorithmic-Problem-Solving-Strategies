//
// Created by 정지민 on 9/4/24.
// https://www.acmicpc.net/problem/11727

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int dp[1005] = {0};

    dp[1] = 1;
    dp[2] = 3;
    dp[3] = dp[1] * 2 + dp[2];
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
    }

    cout << dp[n];
}