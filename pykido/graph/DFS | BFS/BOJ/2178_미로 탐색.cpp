//
// Created by 태윤맥북 on 4/17/24.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int maze_map[101][101];
int visited[101][101] = {};


int bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(0,0));
    visited[0][0] = 1;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i ++) {
            int new_x = now_x + dx[i];
            int new_y = now_y + dy[i];

            if (new_x >= 0 && new_x < M && new_y >= 0 && new_y < N && !visited[new_y][new_x] && maze_map[new_y][new_x] == 1) {
                q.push(make_pair(new_x,new_y));
                visited[new_y][new_x] = visited[now_y][now_x] + 1;
            }
        }
    }

    return visited[N-1][M-1];
}

int main() {
    // 입력 받기
    cin >> N >> M;

    fill_n(&visited[0][0], N * M, false);

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            maze_map[i][j] = line[j] - '0'; // 문자열로 입력 받은 미로를 정수로 변환하여 저장
        }
    }

    // bfs 호출
    cout << bfs();

    return 0;
}
