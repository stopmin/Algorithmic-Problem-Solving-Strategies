//
// 1. 입력 받을 떄 일반인과 적록색약인 사람이 보는 구역 배열을 다르게 설정하자.
// 2. bfs를 통해 현재 행의 구역을 전부 방문 처리하고, 구역 수 += 1

#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int N;
char r_b_blind_area[101][101];
char general_area[101][101];
bool visited[101][101];


 void bfs(int row, int col, int flag) {
    queue<pair<int ,int> > q;
    q.push(make_pair(row, col));
    visited[row][col] = true;   // 현재 위치 방문 처리
    char area[101][101]; // 구역

    // flag에 따라 다른 배열의 복사
    if (flag == 1) {    // 적록색약 아님
        memcpy(area, general_area, sizeof(general_area));
    } else {            // 적록색약임
        memcpy(area, r_b_blind_area, sizeof(r_b_blind_area));
    }

    while(!q.empty()) {
        // 현재 행렬
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();

        int next_row, next_col;
        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            next_row = cur_row + dr[i];
            next_col = cur_col + dc[i];

            // 범위 밖이면 continue
            if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N) continue;

            // 같은 구역이고 방문처리가 안되었다면!
            if (area[next_row][next_col] == area[cur_row][cur_col] && !visited[next_row][next_col]) {
                q.push(make_pair(next_row, next_col));
                visited[next_row][next_col] = true;
            }
        }
    }

}

// 방문 배열 전부 false 넣어주기
void reset() {
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    // 입력 받기
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == 'G') { // 적록색약은 G를 전부 R로 입력 받자!!
                r_b_blind_area[i][j] = 'R';
                general_area[i][j] = str[j];
            } else {
                r_b_blind_area[i][j] = str[j];
                general_area[i][j] = str[j];
            }
        }
    }

    // bfs 구현
    // 1. 일반인이 봤을 때 구역의 수
    reset();
    int result1 = 0;
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i,j, 1);
                result1 += 1;
            }
        }
    }

    // 2. 적록색약이 봤을 때 구역의 수
    reset();
    int result2 = 0;
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i,j, 2);
                result2 += 1;
            }
        }
    }

    cout << result1 << endl;
    cout << result2 << endl;
    return 0;
}


