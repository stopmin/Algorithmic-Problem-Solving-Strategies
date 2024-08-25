//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/13300

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pair<int, int> s[1005];

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> s[i].second >> s[i].first;

    sort(s, s + n);

    int ans = 1;
    int sex = s[0].second;
    int age = s[0].first;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i].first != age) {
            age = s[i].first;
            sex = s[i].second;
            cnt = 1;
            ans++;
        } else if (s[i].second != sex) {
            age = s[i].first;
            sex = s[i].second;
            cnt = 1;
            ans++;
        } else {
            cnt++;
        }

        if (cnt > k) {
            ans++;
            cnt %= k;
        }
    }
    cout << ans;
}
