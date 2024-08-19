//
// Created by 정지민 on 8/19/24.
//
#include <bits/stdc++.h>

using namespace std;
int n;
int stair[305];
int d[305];

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> stair[i];

    d[1] = stair[1];
    d[2] = d[1] + stair[2];

    for (int i = 3; i <= n; i++)
        d[i] = stair[i] + max(d[i - 2], d[i - 3] + stair[i - 1]);

    cout << d[n];
}