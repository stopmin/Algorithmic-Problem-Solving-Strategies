//
// Created by 정지민 on 8/17/24.
//

#include <bits/stdc++.h>

using namespace std;
int N, S;
int ans;
bool isused[21];
int arr[21];

void func(int cur, int depth, int idx) {
    if (cur == S && depth != 0) ans++;
    for (int i = idx; i < N; i++) {
        if (!isused[i]) {
            isused[i] = true;
            depth++;
            func(cur + arr[i], depth, i);
            depth--;
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    func(0, 0, 0);
    cout << ans;
}
