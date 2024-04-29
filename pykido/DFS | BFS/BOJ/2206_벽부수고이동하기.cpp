//
// Created by 태윤맥북 on 4/19/24.
// 1. 시작은 무조건 0,0 끝은 무조건 M-1, N-1일 것이다. (좌표값 기준)
// 2. 완전탐색으로 모든 벽을 한 번씩 뚫고 목적지에 도착하는 것은 시간 초과 발생!!
// 3. 따라서 2가지 경우로 나눠야한다.
// (1) 다음 칸이 벽이고 벽을 부술 수 있다면? cnt = 1로 증가시켜주고 이동 거리 추가
// (2) 다음 칸이 벽이 아니고 방문하지 않았다면? cnt는 그대로 0이고 이동 거리 추가
// !!!! push한다는 것 자체가 이동한다는 것이군...
// 이 문제의 핵심은 벽을 부수고 이동하는 것과 벽을 부수지 않고 이동하는 것의 방문을 다르게 처리해야한다는 것이다-!!!

// 앞으로 dr[4], dc[4] 사용하자

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct coordinate {
    int row;
    int col;
    int cnt;
};

int N, M; // N : 행, M : 열
int land[1001][1001] = {};  // 전부 0으로 초기화
int visited[1001][1001][2] = {};    // [0] : 벽을 부수지 않은 채 이동, [1] : 벽을 한 번 부순 채 이동
queue<coordinate> q;
int dr[4] = {0,1,0,-1}; // 행
int dc[4] = {1,0,-1,0}; // 열

int bfs() {
    coordinate start = {0,0,0};
    q.push(start); // 시작 지점은 무조건 0,0, 벽 부순 횟수는 0
    visited[0][0][0] = 1;

    while (!q.empty()) {
        // 현재 위치 및 벽을 부숫 횟수
        int now_row = q.front().row;
        int now_col = q.front().col;
        int cnt = q.front().cnt;
        q.pop();

        // 도착지에 도착했다면 결과값 return해주기
        if (now_row == (N-1) && now_col == (M-1)) return visited[now_row][now_col][cnt];

        for (int i = 0; i < 4; i++) {
            int new_row = now_row + dr[i];  // 행 이동
            int new_col = now_col + dc[i];  // 열 이동

            if (new_row >= N || new_col < 0 || new_col >= M || new_row < 0) continue;   // 범위에 벗어나면 continue

            if (land[new_row][new_col] == 1 && cnt == 0) { // 다음 칸이 벽이고 벽을 부술 수 있다면 (벽을 부술 수 있다는 것 자체가 처음 방문한다는 거임. 왜냐하면 한 번만 부술 수 있으니깐)
                coordinate new_coordinate = {new_row, new_col, cnt + 1};
                q.push(new_coordinate);
                visited[new_row][new_col][cnt + 1] = visited[now_row][now_col][cnt] + 1;
            } else if (land[new_row][new_col] == 0 && visited[new_row][new_col][cnt] == 0) {  // 다음 칸이 벽이 아니고 방문하지 않았을 때
                coordinate new_coordinate = {new_row, new_col, cnt};
                q.push(new_coordinate);
                visited[new_row][new_col][cnt] = visited[now_row][now_col][cnt] + 1;
            }
        }
    }


    return -1;
}

int main() {
    // 입력 받기
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string line ;
        cin >> line;
        for (int j = 0; j < line.size(); j ++) {
            land[i][j] = line[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}