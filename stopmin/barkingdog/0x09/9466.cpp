//
// Created by 정지민 on 8/28/24.
// https://www.acmicpc.net/problem/9466
#include <bits/stdc++.h>
using namespace std;

int t;
int board[100005];
bool visited[100005], finished[100005];
int teamSize;

void dfs(int node) {
    visited[node] = true;
    int next = board[node];

    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        for (int cur = next; cur != node; cur = board[cur])
            teamSize++;
        teamSize++;
    }
    finished[node] = true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> board[i];
            visited[i] = finished[i] = false;
        }

        teamSize = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i);
        }

        cout << n - teamSize << '\n';
    }
}
