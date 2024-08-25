//
// Created by 정지민 on 8/25/24.
// https://www.acmicpc.net/problem/1026
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int s;
    int a[51], b[51];

    cin >> s;
    for (int i = 0; i < s; i++)
        cin >> a[i];
    for (int i = 0; i < s; i++)
        cin >> b[i];

    sort(a, a+s);
    sort(b, b+s);
    int ans = 0;

    for (int i = 0; i < s; i++)
        ans += a[i] * b[s - i - 1];

    cout << ans;
}
