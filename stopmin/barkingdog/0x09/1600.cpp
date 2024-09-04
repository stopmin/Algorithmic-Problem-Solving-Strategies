//
// Created by 정지민 on 9/2/24.
// https://www.acmicpc.net/problem/1600

#include <bits/stdc++.h>
using namespace std;

struct geocode {
    int x, y, k, count;
};

int dx8[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy8[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dx4[4] = {0, 1, 0, -1};
int dy4[4] = {1, 0, -1, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, w, h;
    cin >> k >> w >> h;

    vector<vector<int>> board(h, vector<int>(w));
    vector<vector<vector<int>>> visited(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    queue<geocode> q;
    q.push({0, 0, k, 0});
    visited[0][0][k] = 0;

    while (!q.empty()) {
        geocode cur = q.front(); q.pop();

        // 목표 지점에 도달한 경우
        if (cur.x == h - 1 && cur.y == w - 1) {
            cout << cur.count << '\n';
            return 0;
        }

        // 말처럼 이동하는 경우
        if (cur.k > 0) {
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.x + dx8[dir];
                int ny = cur.y + dy8[dir];
                int nk = cur.k - 1;
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (board[nx][ny] == 1 || visited[nx][ny][nk] != -1) continue;
                visited[nx][ny][nk] = cur.count + 1;
                q.push({nx, ny, nk, cur.count + 1});
            }
        }

        // 일반 이동하는 경우
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx4[dir];
            int ny = cur.y + dy4[dir];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (board[nx][ny] == 1 || visited[nx][ny][cur.k] != -1) continue;
            visited[nx][ny][cur.k] = cur.count + 1;
            q.push({nx, ny, cur.k, cur.count + 1});
        }
    }

    cout << -1 << '\n';
    return 0;
}
