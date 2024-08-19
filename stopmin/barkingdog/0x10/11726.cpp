//
// Created by 정지민 on 8/19/24.
//

#include <bits/stdc++.h>

using namespace std;
int n;
int d[2000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= 1000; i++)
        d[i] = (d[i - 1] + d[i - 2]) % 10007;

    cout << d[n];
}