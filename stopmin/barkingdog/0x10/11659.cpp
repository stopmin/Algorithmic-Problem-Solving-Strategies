//
// Created by 정지민 on 8/19/24.
//
#include <bits/stdc++.h>

using namespace std;
int n, m;
int num[100005];
int d[100005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 0; i < n; i++)
        d[i + 1] = d[i] + num[i];

    while (m--) {
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i - 1] << '\n';
    }
}