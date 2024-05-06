#include <iostream>
#include <vector>
using namespace std;

int C; // 테스트 케이스의 수

const int coverType[4][3][2] = {
        {{0,0}, {1,0}, {0,1}},
        {{0,0}, {0,1}, {1,1}},
        {{0,0}, {1,0}, {1,1}},
        {{0,0}, {1,0}, {1,-1}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
    bool ok = true;

    // 블록을 덮을 수 있는지 확인
    for (int i = 0; i < 3; i++) {
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];

        if(ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) { // 보드를 벗어나는 경우
            ok = false;
        } else if((board[ny][nx] += delta) > 1) { // 이미 덮인 경우
            ok = false;
        }
    }

    return ok;
}

int cover(vector<vector<int>>& board) {
    int y = -1, x = -1;

    // 가장 윗줄 왼쪽에 있는 빈칸을 찾는다.
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    // 기저 사례: 모든 칸을 채웠으면 1을 반환
    if (y == -1) return 1;

    int ret = 0;

    for (int type = 0; type < 4; type++) {
        if (set(board, y, x, type, 1)) {
            ret += cover(board);
        }

        // 덮었던 블록을 다시 없애기
        set(board, y, x, type, -1);
    }

    return ret;
}


int main() {
    cin >> C;

    while(C--){
        int H,W; // H: 세로, W: 가로
        cin >> H >> W;

        vector<vector<int>> board(H, vector<int>(W, 0));

        for (int i = 0; i < H; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < W; j++) {
                if(line[j] == '#') {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }

        cout << cover(board) << endl;
    }
}
