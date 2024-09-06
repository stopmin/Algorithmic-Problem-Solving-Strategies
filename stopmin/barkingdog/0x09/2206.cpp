//
// Created by 정지민 on 8/28/24.
// https://www.acmicpc.net/problem/2206

#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, break_wall;
};

int n, m;
char board[1005][1005];
int visited[1005][1005][2]; // 0: 벽을 부수지 않고, 1: 벽을 부수고

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs() {
    queue<State> Q;
    Q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (!Q.empty()) {
        State cur = Q.front(); Q.pop();
        int x = cur.x, y = cur.y, break_wall = cur.break_wall;

        if (x == n-1 && y == m-1) return visited[x][y][break_wall];

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (board[nx][ny] == '1' && break_wall == 0 && visited[nx][ny][1] == 0) {
                visited[nx][ny][1] = visited[x][y][0] + 1;
                Q.push({nx, ny, 1});
            }

            if (board[nx][ny] == '0' && visited[nx][ny][break_wall] == 0) {
                visited[nx][ny][break_wall] = visited[x][y][break_wall] + 1;
                Q.push({nx, ny, break_wall});
            }
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    memset(visited, 0, sizeof(visited));
    int ans = bfs();

    cout << ans;
}
