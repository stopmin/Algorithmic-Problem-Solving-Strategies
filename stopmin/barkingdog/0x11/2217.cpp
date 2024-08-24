//
// Created by 정지민 on 8/25/24.
// https://www.acmicpc.net/problem/2217

#include <bits/stdc++.h>

using namespace std;
int n;
int r[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> r[i];
    sort(r, r + n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, r[n-i] * i);

    cout << ans;
}
