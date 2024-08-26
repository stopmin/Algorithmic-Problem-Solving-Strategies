//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/6198
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    stack<int> s;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() <= heights[i]) {
            s.pop();
        }
        ans += s.size();
        s.push(heights[i]);
    }

    cout << ans << "\n";
}

