//
// Created by 태윤맥북 on 6/15/24.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, R, C, K, cnt;
int dr[4] = {0,1,0,-1}; // 행
int dc[4] = {1,0,-1,0}; // 열
int visited[51][51] = {};
int cabbage_field[51][51] = {};
queue<pair<int, int> > q;

void bfs(int r, int c) {
    q.push(make_pair(r,c));
    visited[r][c] = 1;
    cnt += 1;

    while(!q.empty()) {
        int now_row = q.front().first;
        int now_col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = now_row + dr[i];
            int next_col = now_col + dc[i];

            if (next_col < 0 || next_col >= C || next_row < 0 || next_row >= R) continue;

            if (cabbage_field[next_row][next_col] == 1 && visited[next_row][next_col] == 0) {
                q.push(make_pair(next_row,next_col));
                visited[next_row][next_col] = 1;
            }
        }
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> R >> C >> K;
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(cabbage_field, 0, sizeof(cabbage_field));

        for (int j = 0; j < K; j++) {
            int r, c;
            cin >> r >> c;
            cabbage_field[r][c] = 1;
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (cabbage_field[r][c] == 1 && visited[r][c] == 0) {
                    bfs(r,c);
                }
            }
        }


        cout << cnt << endl;
    }

    return 0;
}