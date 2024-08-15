//
// Created by 정지민 on 8/15/24.
//
#include <bits/stdc++.h>

using namespace std;
int dx[] = {0, 0, 1, 0, 0, -1};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {1, 0, 0, -1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, H;
    cin >> M >> N >> H;
    int ans = 0;
    int tomato[101][101][101];
    int dist[101][101][101] = {0,};
    queue<tuple<int, int, int> > Q;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> tomato[k][i][j];
                if (tomato[k][i][j] == 1) {
                    Q.push({k, i, j});
                } else if (tomato[k][i][j] == 0) {
                    dist[k][i][j] = -1;
                }
            }
        }
    }


    while (!Q.empty()) {
        auto [z, x, y] = Q.front();
        Q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || nz < 0 || nz >= H || dist[nz][nx][ny] != -1) continue;
            Q.push({nz, nx, ny});
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            ans = max(ans, dist[nz][nx][ny]);
        }
    }


    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (dist[k][i][j] == -1) ans = -1;

    cout << ans;
}