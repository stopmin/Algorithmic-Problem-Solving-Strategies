//
// Created by 정지민 on 8/17/24.
//

#include <bits/stdc++.h>

using namespace std;
int N, S;
int ans = 0;
int arr[30];

void func(int cur, int tot) {
    if (cur == N ) {
        if(tot==S) ans++;
        return;
    }
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    func(0, 0);
    if(S==0) ans--;
    cout << ans;
}
