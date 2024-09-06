//
// Created by 정지민 on 8/31/24.
// https://www.acmicpc.net/problem/2146
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point {
    int x, y, dist;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<Point> q;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    // 섬에 고유 ID 부여
    int island_id = 2; // 섬 ID를 2부터 시작 (1은 입력에서 사용됨)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1) {
                q.push({i, j, 0});
                board[i][j] = island_id;

                while (!q.empty()) {
                    auto p = q.front(); q.pop();
                    for (int d = 0; d < 4; ++d) {
                        int nx = p.x + dx[d], ny = p.y + dy[d];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < N && board[nx][ny] == 1) {
                            board[nx][ny] = island_id;
                            q.push({nx, ny, 0});
                        }
                    }
                }
                island_id++;
            }
        }
    }

    // 최단 다리 찾기
    int ans = INT_MAX;
    for (int id = 2; id < island_id; ++id) {
        queue<Point> q;
        // 거리 초기화
        for (int i = 0; i < N; ++i) fill(dist[i].begin(), dist[i].end(), -1);

        // 현재 섬의 모든 점을 큐에 넣기
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == id) {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }

        // BFS로 다른 섬까지의 최단 경로 찾기
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = p.x + dx[d], ny = p.y + dy[d];
                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    if (board[nx][ny] != 0 && board[nx][ny] != id) {
                        ans = min(ans, dist[p.x][p.y]);
                        break; // 다른 섬을 찾았으므로 중지
                    }
                    if (board[nx][ny] == 0 && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[p.x][p.y] + 1;
                        q.push({nx, ny, dist[nx][ny]});
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
