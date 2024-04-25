//
// Created by 태윤맥북 on 4/18/24.
//
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;   // 세로 길이 : N, 가로 길이 : M, 쓰레기 개수 : K
int food_map[101][101] = {}; // 0으로 초기화
bool visited[101][101];
int result = 0; // 결과값
queue<pair<int, int> > q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int rows, int cols) {
    q.push(make_pair(rows, cols));
    visited[rows][cols] = true;
    int cnt = 1;

    while (!q.empty()) {
        int now_rows = q.front().first;
        int now_cols = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_rows = now_rows + dy[i];
            int new_cols = now_cols + dx[i];

            if (new_cols < 0 || new_cols >= M || new_rows < 0 || new_rows >= N) continue;

            if (!visited[new_rows][new_cols] && food_map[new_rows][new_cols] == '#') {
                q.push(make_pair(new_rows,new_cols));
                visited[new_rows][new_cols] = true;
                cnt += 1;
            }

        }
    }

    result = max(cnt, result);
}


int main() {
    // 2 3 : 1행 2열
    // 입력 받기
    cin >> N >> M >> K; // N : 행, M : 열
    for (int i = 0; i < K; i++) {
        int col, row;
        cin >> col >> row;
        food_map[col-1][row-1]  = '#';
    }

    fill_n(&visited[0][0], N * M, false);

    for (int i = 0; i < N; i++) {   // i : 행, j : 열
        for (int j = 0; j < M; j++) {
            if (food_map[i][j] == '#') {
                bfs(i, j);
            }
        }
    }

    cout << result;

    return 0;
}