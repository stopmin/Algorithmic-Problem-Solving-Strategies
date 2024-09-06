//
// Created by 정지민 on 9/5/24.
// https://www.acmicpc.net/problem/11055

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long n;
    cin >> n;
    long long arr[1005] = {0,};
    long long dp[1005] = {0,};

    for (int i = 0; i < n; i++) cin >> arr[i];


    long long ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout<<ans;
}