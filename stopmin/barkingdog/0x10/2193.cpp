// 쉽다.
// Created by 정지민 on 9/5/24.
// https://www.acmicpc.net/problem/2193

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long dp[95];
    int n; cin >> n;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = dp[2] + dp[3];

    for (int i = 5; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[n];
}