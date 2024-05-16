// [문제 해결의 흐름]
// 1. 처음 입력 받을 때 바이러스 위치들을 전부 queue에 저장하자
// 2. bfs 구현 (Tg의 시간동안 매번 bfs를 호출하지 않고 한 번의 호출로 구현해보자!)
//  (1) 우선순위를 부여하자! (Tg의 시간동안 building가 감염되는 것이 virus가 감염시키는 것보다 우선시되어야 하기 떄문이다)
//  (2) virus가 감염시키며 building을 만난다면 q_building에 넣어준다.
//  (3) q_building에 있는 값들은 감염된 값들이므로 매초 감염 스택을 쌓아주자. (만약, 감염이 끝났다면 더 이상 building이 아닌 virus로 간주한다)
//  (4) q_virus와 q_building 둘 중 하나가 빌 때까지 반복한다.

#include <iostream>
#include <queue>

using namespace std;

struct q_val {
    int row;
    int col;
    int time;
};

int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};

int R, C;
int Tg, Tb, X, B;
char pnuMap[1001][1001];
queue<q_val> q_virus;
queue<q_val> q_building;
int visited[1001][1001] = {};
int virus[1001][1001] = {};

q_val search() {
    if (q_virus.empty()) {
        q_val ret_val = q_building.front();
        q_building.pop();
        return ret_val;
    }

    if (q_building.empty()) {
        q_val ret_val = q_virus.front();
        q_virus.pop();
        return ret_val;
    }

    // building가 감염되는 것이 virus가 감염시키는 것보다 우선시되어야 한다.
    int virus_time = q_virus.front().time;
    int building_time = q_building.front().time;
    if (virus_time < building_time) {
        q_val ret_val = q_virus.front();
        q_virus.pop();
        return ret_val;

    } else {
        q_val ret_val = q_building.front();
        q_building.pop();
        return ret_val;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // 1. 입력 받기
    cin >> R >> C;
    cin >> Tg >> Tb >> X >> B;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> pnuMap[r][c];
            if (pnuMap[r][c] == '*') { // 초기 바이러스 위치
                q_val firs_val = {r,c,0};
                q_virus.push(firs_val);
                visited[r][c] = 1;
            }
        }
    }

    // 2. bfs 구현
    while(!q_virus.empty() || !q_building.empty()) {
        q_val current_val = search();
        int cur_row = current_val.row;
        int cur_col = current_val.col;
        int cur_time = current_val.time;

        if (cur_time > Tg) break;

        virus[cur_row][cur_col] = 1;
        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int next_r = cur_row + dr[i];
            int next_c = cur_col + dc[i];

            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
            if (visited[next_r][next_c]) continue;

            visited[next_r][next_c] = 1;

            if (pnuMap[next_r][next_c] == '#') {
                q_val next_val = {next_r,next_c,cur_time + Tb + 1};
                q_building.push(next_val);
            } else if (pnuMap[next_r][next_c] == '.') {
                q_val next_val = {next_r,next_c,cur_time + 1};
                q_virus.push(next_val);
            }
        }
    }

    // 3. 출력하기
    bool safe = false;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (virus[r][c] == 0) {
                safe = true;
                cout << r + 1 << " " << c + 1 << "\n";
            }
        }
    }
    if (!safe) cout << -1 << "\n";

    return 0;
}