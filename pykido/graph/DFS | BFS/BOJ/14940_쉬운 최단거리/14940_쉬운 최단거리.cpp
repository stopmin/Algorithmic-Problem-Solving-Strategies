//
//

#include <iostream>
#include <queue>

using namespace std;

int R, C;
int land[1001][1001];
int visited[1001][1001] = {};
queue<pair<int, int> > q;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bfs() {
    while(!q.empty()) {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
            if (visited[next_r][next_c] > 0) continue;

            if (land[next_r][next_c] == 1) {
                visited[next_r][next_c] = visited[cur_r][cur_c] + 1;
                q.push(make_pair(next_r,next_c));
            }
        }
    }
}


int main() {
    // 1. 입력 받기
    cin >> R >> C;
    for (int r = 0 ; r < R; r++) {
        for (int c = 0; c < C; c++) {
            int land_val;
            cin >> land_val;
            land[r][c] = land_val;
            if (land_val == 2) {
                q.push(make_pair(r,c));
            }
        }
    }

    // 2. bfs 구현
    bfs();

    // 3. 결과 출력
    for (int r = 0 ; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (visited[r][c] == 0 && land[r][c] == 1) {
                cout << "-1 " ;
            } else {
                cout << visited[r][c] << " ";

            }
        }
        cout << "\n";
    }

    return 0;
}