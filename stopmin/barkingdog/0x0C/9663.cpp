//
// Created by 정지민 on 8/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int n;
bool col[15], diag1[30], diag2[30];
int ans = 0;

void func(int k) {
    if (k == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !diag1[k + i] && !diag2[k - i + n - 1]) {
            col[i] = diag1[k + i] = diag2[k - i + n - 1] = true;
            func(k + 1);
            col[i] = diag1[k + i] = diag2[k - i + n - 1] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;
    func(0);
    cout<<ans;
}