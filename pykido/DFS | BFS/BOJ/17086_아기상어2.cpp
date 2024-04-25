//
// Created by 태윤맥북 on 4/19/24.
// 1. 안전거리 : 현재 위치한 칸과 가장 가까운 아기 상어와의 거리이다!
// 2. bfs를 구현할 때 while문 속에서 for문을 돌며 안전거리를 찾자. (방문처리 배열로 안전거리 구하기)

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int shark_map[51][51] = {};
int dx[8] = {0, 0, 1, -1, 1, -1 ,1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int result = 0;

int bfs(int row, int col) {
    queue<pair<int, int> > q;
    int visited[51][51] = {};   // 전부 0으로 초기화
    q.push(make_pair(row, col));
    visited[row][col] = 0;

    while(!q.empty()) {
        // 상어가 없는 위치 now에서 계속 탐색을 이어간다.
        int now_row = q.front().first;
        int now_col = q.front().second;
        q.pop();

        // 8방향 탐색
        for (int i = 0; i < 8; i++) {
            int new_row = now_row + dy[i];
            int new_col = now_col + dx[i];

            // 범위값 이탈시 continue
            if (new_col < 0 || new_col >= M || new_row < 0 || new_row >= N) continue;

            // 상어 발견 !!
            if (shark_map[new_row][new_col] == 1) {
                return visited[now_row][now_col] + 1;
            }

            // 상어가 없다면 계속 탐색
            if (visited[new_row][new_col] == 0) {
                q.push(make_pair(new_row, new_col));    // 0의 위치를 넣어준다.
                visited[new_row][new_col] = visited[now_row][now_col] + 1;
            }

        }
    }
}


int main() {
    cin >> N >> M;

    // 상어 위치 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            cin >> val;
            shark_map[i][j] = val;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (shark_map[i][j] == 0) { // 상어가 없는 위치일 경우
                result = max(bfs(i, j), result); // i : row_num, j : col_num
            }
        }
    }

    cout << result;

    return 0;
}