//
// Created by 태윤맥북 on 4/19/24.
//
// 1. 7569 토마토 문제와 매우 비슷한듯?
// 2. 무한 루프를 통해 0 0 0이 입력될 때까지 입력 받자! (무한 루프를 통해 여러 테스트케이스를 거치기에 초기화과정을 필수다!)
// 3. 시작 지점부터 6방향을 탐색하며 아직 방문하지 않았고 막힌 곳(#)이 아니라면 이동하기
// 4. 계속 이동하다가 도착 지점(E)을 만나면 이동시간 반환하기

#include <iostream>
#include <queue>

using namespace std;

// 상범 빌딩 좌표값 자료형
struct coordinate {
    int height;
    int rows;
    int cols;
};

// 6방향 탐색
int dc[6] = {0, 0, -1, 1, 0, 0}; // 열 이동
int dr[6] = {-1, 1, 0, 0, 0, 0}; // 행 이동
int dh[6] = {0, 0, 0, 0, -1, 1}; // 위 아래 이동

int L, R, C; // L : 상범 빌딩 층 수 , R : 한 층의 행 수, C : 한 층의 열 수
char building[31][31][31]; // 상범 빌딩 좌표값
queue<coordinate> q;
int visited[31][31][31] = {}; // 전부 0으로 초기화

int bfs() {
    while(!q.empty()) {
        // 현재 위치
        int cur_h = q.front().height;
        int cur_r = q.front().rows;
        int cur_c = q.front().cols;
        q.pop();

        // 도착 지점이라면 이동시간 반환하기
        if (building[cur_h][cur_r][cur_c] == 'E') return visited[cur_h][cur_r][cur_c];

        // 6방향 탐색
        for (int i = 0; i < 6; i++) {
            int next_h = cur_h + dh[i];
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            // 범위 밖이면 continue
            if (next_h < 0 || next_h >= L || next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;

            // 아직 가보지 않은 곳이고 #이 아니라면 이동 (#이 아니란 것은 .이거나 E라는 뜻)
            if (visited[next_h][next_r][next_c] == 0 && building[next_h][next_r][next_c] != '#') {
                coordinate next_coordinate = {next_h,next_r,next_c};
                q.push(next_coordinate);
                visited[next_h][next_r][next_c] = visited[cur_h][cur_r][cur_c] + 1; // 이동 시간 + 1
            }
        }
    }

   return 0;
}

int main() {
    while(true) {
        cin >> L >> R >> C;

        // 무한 루프 종료 조건
        if (L == 0 && R == 0 && C == 0) break;

        // visited 배열 초기화
        fill_n(&visited[0][0][0], 31 * 31 * 31, 0);
        // queue 초기화
        while (!q.empty()) {
            q.pop();
        }

        // 입력 받기
        for (int l = 0; l < L; l++) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    char val;
                    cin >> val;
                    building[l][r][c] = val;

                    if (val == 'S') {   // 시작 지점 넣어주기
                        coordinate s = {l, r, c};
                        q.push(s);
                    }
                }
            }
        }

        // 출력하기
        int result = bfs();
        if (result != 0) {
            cout << "Escaped in " << result << " minute(s)." << endl;
        } else {
            cout << "Trapped!" << endl;
        }

    }

    return 0;
}