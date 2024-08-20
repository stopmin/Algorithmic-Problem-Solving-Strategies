//
// Created by 정지민 on 8/19/24.
//

#include <bits/stdc++.h>

using namespace std;
int n;
int d[1000005]; // 값 테이블
int pre[1000005]; // 경로 복원용 테이블

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1] = 0;
    d[2] = 1;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
            d[i] = d[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
            d[i] = d[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << d[n] << '\n';
    int cur = n;
    while (true) {
        cout << cur << ' ';
        if(cur==1) break;
        cur = pre[cur];
    }
}