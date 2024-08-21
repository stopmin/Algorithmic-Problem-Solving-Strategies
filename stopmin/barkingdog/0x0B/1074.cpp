//
// Created by 정지민 on 8/17/24.
//
#include <bits/stdc++.h>

using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0;
    int half = 1 << (n - 1);
    // (r,c)가 1번 사각형일 때
    if (r < half && c < half) return func(n - 1, r, c);
    // (r,c)가 2번 사각형일 때
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
    // (r,c)가 3번 사각형일 때
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
    // (r,c)가 4번 사각형일 때
    return 3 * half * half + func(n - 1, r - half, c - half);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, r, c;
    cin >> N >> r >> c;
    cout << func(N, r, c);
}