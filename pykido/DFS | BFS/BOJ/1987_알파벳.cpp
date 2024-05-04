// 1. 좌측 상단에서부터 시작해서 상하좌우로 탐색하며 이동할 수 있는 최대 칸 수를 구해야 하는 문제이다.
// 2. 주어진 그래프에 대해 완전탐색을 통해 최대 칸 수를 구해 보자. (dfs 이용!!)
// 3. 이때, 알파벳 개수는 26개이므로 26개의 인덱스를 갖는 인트형 방문배열을 통해 방문처리해주자.

#include <iostream>

using namespace std;

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int R, C;
int result_cnt = 0;
char alphabet_map[20][20];  // 대문자 알파벳들을 입력 받을 이차원 배열
int visited[26] = {}; // 전부 0으로 초기화


void dfs(int r, int c, int cur_cnt) {
    // 지나갈 수 있는 최대 칸 수 갱신
    result_cnt = max(result_cnt, cur_cnt);

    // 상하좌우 탐색
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // 범위 밖으로 벗어나면 continue
        if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

        // backtracking
        if (!visited[alphabet_map[nr][nc] - 'A']) {
            visited[alphabet_map[nr][nc] - 'A'] += 1;
            dfs(nr,nc, cur_cnt + 1);
            visited[alphabet_map[nr][nc] - 'A'] -= 1;
        }
    }


}


int main() {
    // 입력 받기
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            char val;
            cin >> val;
            alphabet_map[r][c] = val;
        }
    }

    // dfs 구현
    visited[alphabet_map[0][0] - 'A'] += 1;
    dfs(0,0,1);

    // 결과 출력
    cout << result_cnt;

    return 0;
}
