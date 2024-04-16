//
// Created by 태윤맥북 on 4/15/24.
// 1, 토마토가 익은 상태(1)라면 방문처리하고 주변토마토들을 변화시키자. (단, 들어있지 않은 칸은 변화 X)
// 2. 결과값은 5015번 풀었을 때처럼 처리하면 될 거 같다.
//

#include <iostream>
#include <queue>

using namespace std;

// 토마토의 좌표값
struct coordinate {
    int x;
    int y;
    int z;
};


int M, N, H, tomato; // M : 가로 칸 수, N : 세로 칸 수, H : 상자의 높이, tomato : 토마토 개별 정보
int tomato_box[101][101][101]; // 입력 받을 배열 설정
int visited[101][101][101] = {}; // 전부 0으로 초기화
queue<coordinate> q;

int day = 0; // 토마토 익는 날 계산

// 익은 토마토 주위의 6방향 표시
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};


int bfs() {
    while(!q.empty()) {
        // 익은 토마토 위치
        int now_x = q.front().x;
        int now_y = q.front().y;
        int now_z = q.front().z;
        q.pop();

        // 익은 토마토 주위로 6방향 탐색
        for (int i = 0; i < 6; i++) {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            int nz = now_z + dz[i];

            // 범위 밖이면 continue
            if (nx < 0 or nx >= M or ny < 0 or ny >= N or nz < 0 or nz >= H) continue;

            // 안 익은 토마토가 있고 방문한 적이 없으면 익은 토마토로 바꾸고 queue에 넣어주기
            if (tomato_box[nz][ny][nx] == 0 and visited[nz][ny][nx] == -1) {
                coordinate add_tomato;
                tomato_box[nz][ny][nx] = 1;
                add_tomato.x = nx;
                add_tomato.y = ny;
                add_tomato.z = nz;
                q.push(add_tomato);
                // 5015번 풀었을 떄와 같은 방법!
                visited[nz][ny][nx] = visited[now_z][now_y][now_x] + 1;
            }
        }
    }

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (tomato_box[h][n][m] == 0) return -1; // 토마토가 모두 익지 못하는 경우
                day = max(day, visited[h][n][m]);
            }
        }
    }


    return day;
}

int main() {
    cin >> M >> N >> H;
    fill_n(&tomato_box[0][0][0], 101 * 101 * 101, -1);  // 아직 입력 받지 않았기에 토마토 없음!

    // 토마토 입력 받기
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> tomato;
                tomato_box[h][n][m] = tomato;

                coordinate tomato_coord;
                tomato_coord.x = m;
                tomato_coord.y = n;
                tomato_coord.z = h;

                if (tomato == 1) {  // 익은 토마토 정보는 queue에 저장하기
                    q.push(tomato_coord);
                }
                if (tomato == 0) visited[h][n][m] = -1;
            }
        }
    }

    cout << bfs();

    return 0;
}