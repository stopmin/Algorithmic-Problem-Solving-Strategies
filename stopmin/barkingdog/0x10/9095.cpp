//
// Created by 정지민 on 8/19/24.
//
#include <bits/stdc++.h>

using namespace std;

int T;
int d[20] = {0,};

int main(void) {

    cin >> T;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i <= 11; i++)
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    while (T--) {
        int n;
        cin >> n;
        cout << d[n] << '\n';

    }
}