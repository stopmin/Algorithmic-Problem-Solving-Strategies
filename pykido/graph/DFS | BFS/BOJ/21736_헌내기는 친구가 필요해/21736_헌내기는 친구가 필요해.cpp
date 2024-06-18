//
//

#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
int R, C;
char campus_arr[601][601];
int visited[601][601] = {};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfs() {
    int cnt = 0;

    while(!q.empty()) {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
            if (visited[next_r][next_c] > 0) continue;

            visited[next_r][next_c] += 1;

            if (campus_arr[next_r][next_c] == 'P') {
                cnt += 1;
                q.push(make_pair(next_r,next_c));
            } else if (campus_arr[next_r][next_c] == 'O') {
                q.push(make_pair(next_r,next_c));
            }
        }
    }

    return cnt;
}

int main() {
    // 1. 입력 받기
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char map_info;
            cin >> map_info;
            campus_arr[r][c] = map_info;
            if (map_info == 'I') {
                q.push(make_pair(r,c));
                visited[r][c] += 1;
            }
        }
    }


    // 2. bfs
    int result = bfs();
    if (result == 0) {
       cout << "TT" << '\n';
    } else {
        cout << result << '\n';
    }


    return 0;
}
