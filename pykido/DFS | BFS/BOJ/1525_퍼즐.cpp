//
// 1. 입력을 이차원 배열의 형태로 받는다. ex) '103425786'
// 2. bfs를 통해 상하좌우를 탐색한다. (q에 들어가는 값 : 0의 행 열 위치값, 퍼즐 위치 정보 나타낸 문자열)
// 3. 이때, 현재 퍼즐의 형태가 갱신값이기에 퍼즐을 문자열로 치환하여 방문 처리를 시도하자!! (이동하여 특정 위치에 도달하는 문제 : 이동 위치가 갱신 값, 연산하여 특정값을 만드는 문제 : 연산 결과가 갱신 값)
//
// 새롭게 알게 된 내용
// (1) 해시맵
// (2) int to str : to_string() 메서드 사용
// (3) string의 .find() 함수 : 찾으려고 하는 char이 문자열의 몇 번째 인덱스인지 알려줌
// (4) char to int : char - '0'
// (5) int to char : int + '0'


#include <iostream>
#include <queue>
#include <unordered_map> // 해시맵 사용

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct r_c_string { // queue에 저장할 변수의 데이터 타입 지정
    int row;
    int col;
    string str;
};

string answer_str = "123456780"; // 정답이 되는 문자열
unordered_map<string, int> visited; // int 배열은 메모리 초과,, 그래서 해시맵으로 변경

queue<r_c_string> q;



int bfs() {
    visited[q.front().str] = 1; // 처음 위치 방문 처리

    while(!q.empty()) {
        // 현재 행, 열 위치 및 문자열, 그리고 0의 위치
        int cur_r = q.front().row;
        int cur_c = q.front().col;
        string cur_str = q.front().str;
        int zero_position = cur_str.find('0'); // cur_str에서 0의 위치
        q.pop();

        // 반환 조건
        if (cur_str == answer_str) return visited[cur_str] - 1;

        // cur_str를 이차원 int형 배열로 바꾼 뒤 상하좌우 탐색해야 함
        int cur_arr[3][3] = {};
        int index = 0;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                cur_arr[r][c] = cur_str[index] - '0';
                index += 1;
            }
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            // 범위를 벗어나면 continue
            if (next_r < 0 || next_r > 2 || next_c < 0 || next_c > 2) continue;

            // 0의 위치와 next_val의 위치를 바꿔준다.
            string next_str = cur_str;
            int next_position = next_str.find(cur_arr[next_r][next_c] + '0');
            char tmp = next_str[zero_position];
            next_str[zero_position] = next_str[next_position];
            next_str[next_position] = tmp;

            // 첫 방문이라면 queue에 push!!
            if (visited[next_str] == 0) {
                r_c_string next_val;
                next_val.row = next_r;
                next_val.col = next_c;
                next_val.str = next_str;
                q.push(next_val);
                visited[next_str] = visited[cur_str] + 1;
            }
        }
    }

    return -1;
}




int main() {
    // 입력 받기
    r_c_string first_val;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int val;
            cin >> val;
            first_val.str += to_string(val); // 입력 받은 숫자를 문자열로 변환하여 전체 문자열에 결합

            if (val == 0) { // 처음 0의 위치
                first_val.row = r;
                first_val.col = c;
            }
        }
    }
    q.push(first_val);

    cout << bfs(); // 결과 출력

    return 0;
}
