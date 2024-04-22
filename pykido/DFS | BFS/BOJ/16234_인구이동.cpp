//
// 1. main 함수에서 무한루프를 돈다. 무한루프 속 이차원 배열을 돌며 하나씩 bfs에 넣어본다.
// 2. 국경선이 열리는 두 나라를 찾았다면 queue에 넣고 bfs를 통해 그 두 나라와 국경선을 열 수 있는 다른 나라들이 있는지 확인한다.
// 3. 2.에서 찾은 두 나라와 연합을 이루는 나라들의 수, totalN과 좌표들을 찾아내자.
// 4. 3.에서 찾은 값들을 통해 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.


#include <iostream>
#include <queue>

using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

int N, L, R; // 나라는 N x N 크기의 땅, L :
int population_map[51][51] = {};
queue<pair<int, int> > q;
bool visited[51][51];
int flag = 0;

// !! 인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다
// 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
// 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
// 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
// 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
// 연합을 해체하고, 모든 국경선을 닫는다.
void bfs() {
    int totalN = 0; // 연합 수
    int totalP = 0; // 연합의 인구 수
    queue<pair<int, int> > unionQ;  // 연합 단체

    while(!q.empty()) {
        // 현재 위치
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        // 연합에 속함
        unionQ.push(make_pair(cur_row,cur_col));
        totalP += population_map[cur_row][cur_col];
        totalN += 1;    // 연합 수 + 1
        // 현재 i행 j열 인구 수
        int cur_pos = population_map[cur_row][cur_col];
        // 방문처리해주기
        visited[cur_row][cur_col] = true;
        q.pop();

        // 상하좌우 탐색하며 국경선을 열어도 되는지 확인
        for (int i = 0; i < 4; i++) {
            int next_r = cur_row + dr[i];
            int next_c = cur_col + dc[i];
            int next_pos = population_map[next_r][next_c];

            // 범위 벗어나면 continue
            if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;

            // 국경선 열 수 있나??
            if (abs(cur_pos - next_pos) >= L && abs(cur_pos - next_pos) <= R && !visited[next_r][next_c]) {
                flag = 1;
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r,next_c));
            }
        }
    }

    if (totalN != 0) {
        while(!unionQ.empty()) {
            int result_row = unionQ.front().first;
            int result_col = unionQ.front().second;
            unionQ.pop();
            population_map[result_row][result_col] = totalP / totalN;
        }
    }
}


int main() {
    // 입력 받기
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            population_map[i][j] = num;
        }
    }

    // 구현
    int result = 0;
    while(true) {
        // 방문배열 초기화시키기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        }

        flag = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    q.push(make_pair(i, j));
                    bfs();
                }
            }
        }

        if (flag == 0) {
            break;
        } else {
            result += 1;
        }
    }

    cout << result;

    return 0;
}