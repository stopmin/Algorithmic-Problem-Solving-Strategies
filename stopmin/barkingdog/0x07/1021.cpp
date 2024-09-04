// https://www.acmicpc.net/problem/1021

#include <bits/stdc++.h>

using namespace std;
int n, m;
int ans;
queue<int> Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // n: 큐의 크기, m: 뽑아 내려고 하는 수의 위치
    for (int i = 0; i < n; i++)
        Q.push(i + 1);

    while (m--) {
        int x;
        cin >> x;
        int cnt = 0;
        while (Q.front() != x) {
            int front = Q.front();
            Q.pop();
            Q.push(front);
            cnt++;
        }
        if (Q.size() - cnt > cnt) ans += cnt;
        else ans += Q.size() - cnt;
        Q.pop();
    }

    cout << ans;
}

