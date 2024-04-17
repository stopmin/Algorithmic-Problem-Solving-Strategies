//
// Created by 태윤맥북 on 4/17/24.
//

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
char battleground[101][101];
bool visited[101][101];
int W_power = 0;    // 아군 국력
int B_power = 0;    // 적군 국력

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// bfs 구현
int bfs(int row, int col, char color) {
    queue<pair<int, int> > q;
    q.push(make_pair(row,col));
    visited[row][col] = true;
    int cnt = 1;

    while (!q.empty()) {
        int now_row = q.front().first;
        int now_col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_row = now_row + dx[i];
            int new_col = now_col + dy[i];

            if (new_row < 0 || new_row >= M || new_col < 0 || new_col >= N) continue;

            if (!visited[new_row][new_col] && battleground[new_row][new_col] == color) {
                visited[new_row][new_col] = true;
                cnt++;
                q.push(make_pair(new_row, new_col));
            }
        }
    }

    return cnt;
}


int main() {
    // 입력 받기
    cin >> N >> M;  // N : 열, M : 행
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        str.copy(battleground[i], str.length() + 1);
    }
    fill_n(&visited[0][0], M * N, false);


    for (int i = 0; i < M; i++) {   // i : 행, j : 열
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                int power = bfs(i, j, battleground[i][j]);
                if (battleground[i][j] == 'W') W_power += power * power;
                else B_power += power * power;
            }
        }
    }

    cout << W_power << " " << B_power;

    return 0;

}