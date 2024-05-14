// 1. 벡터나 배열을 넘겨준다면 '데이터타입& 변수명'으로 넘겨주기!
// 2. const를 사용해 상수화시킬 수 있다.
// 3. set 메서드를 통해 덮거나 지우는 행위를 동시에 할 수 있다.
// 4. 2차원 배열 board[10][10]; 행의 길이 : board.size(); 열의 길이 : board[0].size();
// 5. 특정한 순서대로 답을 생성하도록 강요할 필요가 있다. 그것은 바로 가장 왼쪽 위부터 덮게 하는 것!!
// 6. 가능한 모든 경우를 다 탐색하기에 백트래킹을 사용하는 것이 바람직하다.

#include <iostream>
#include <vector>

using namespace std;


// 주어진 칸을 덮을 수 있는 4가지 방법
const int coverType[4][3][2] = {
        { {0,0}, {1,0}, {0,1} }, // Type : 0
        { {0,0}, {0,1}, {1,1} }, // Type : 1
        { {0,0}, {1,0}, {1,1} }, // Type : 2
        { {0,0}, {1,0}, {1,-1} } // Type : 3
};

// board의 (r,c)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다.
// delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
// 만약 블록이 제대로 덮이지 않는 경우 false 반환
//  (1) 범위 벗어나는 경우
//  (2) 겹치는 경우
//  (3) 검은 칸을 덮는 경우
bool set(vector<vector<int> >& board, int r, int c, int type, int delta) {
    bool flag = true;

    // 블록을 덮을 수 있는지 확인
    for (int i = 0; i < 3; ++i) {
        int next_r = r + coverType[type][i][0];
        int next_c = c + coverType[type][i][1];

        // 범위 벗어나는 경우
        if (next_r < 0 || next_c < 0 || next_r >= board.size() || next_c >= board[0].size()) flag = false;
        // 겹치거나 검은 칸을 덮는 경우
        else if ((board[next_r][next_c] += delta) > 1) flag = false;
    }

    return flag;
}

// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 구하기
// board[i][j] = 1 (이미 덮인 칸 혹은 검은 칸)
// board[i][j] = 0 (아직 덮이지 않은 칸)
int cover(vector<vector<int> >& board) {
    // 아직 채우지 않은 칸 중 제일 윗줄 왼쪽 칸 찾기
    int r = - 1, c = -1;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            // 아직 채우지 않은 칸 발견
            if (board[i][j] == 0) {
                r = i;
                c = j;
                break;
            }
        }
        if (r != -1) break;
    }

    // 기저 사례 : 모든 칸 채웠으면 1 반환
    if (r == -1) return 1;

    int result = 0;
    for (int type = 0; type < 4; ++type) {
        // 만약 덮을 수 있다면 재귀호출하기
        if (set(board, r, c,type,1)) {
            result += cover(board);
        }

        // 백트래킹
        set(board,r,c,type,-1);
    }

    return result;
}


int main() {
    int T;
    cin >> T;

    for (int t = 0 ; t < T; ++t) {
        int R, C;
        cin >> R >> C;

        vector<vector<int> > board(R, vector<int>(C, 0));

        for (int i = 0; i < R; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < C; ++j) {
                if (line[j] == '#') {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }

        cout << cover(board) << endl;
    }

    return 0;
}