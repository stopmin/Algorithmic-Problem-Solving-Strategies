// 종만북 p.150 보글게임 (문제 ID : BOGGLE, 난이도 : 하)
// 1. 브루트 포스로 풀었음.
// 2. 입력이 잘못되거나 범위에서 벗어난 경우 기저 사례로 택해 맨 처음에 처리하자!
// 3. 최악의 경우 단어 길이 N에 대해 매번 8칸씩 검사하므로 시간 복잡도는 O(8**N)이다.

#include <iostream>

using namespace std;

int dr[8] = {-1,0,1,-1, 1,-1,0,1};
int dc[8] = {1,1,1,0,0,-1,-1,-1};

int C, N;
char board[5][5];

//
bool inRange(int r, int c) {
    if (r < 0 || c < 0 || r >= 5 || c >= 5) return false;
    else return true;
}

bool hasWord(int r, int c, const string& word) {
    // 기저사례 1. 범위 벗어나면 실패
    if (!inRange(r,c)) return false;
    // 기저사례 2. 단어 첫글자와 일치하지 않으면 실패
    if(board[r][c] != word[0]) return false;
    // 기저사례 3. 단어 길이가 1이라면 성공!
    if(word.size() == 1) return true;

    // 인접한 여덟 칸 검사
    for (int direction = 0; direction < 8; ++direction) {
        int nextR = r + dr[direction], nextC = c + dc[direction];
        if (hasWord(nextR, nextC, word.substr(1))) return true;
    }

    // 여덟 칸 검사했지만 모두 실패했다면 단어를 찾지 못한 것 !
    return false;
}


int main() {
    cin >> C;
    for (int t = 0; t < C; ++t) {
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                cin >> board[r][c];
            }
        }

        cin >> N;
        string wordArr[10];
        for (int i = 0; i < N; ++i) {
            string word;
            cin >> word;
            wordArr[i] = word;

            bool result = false;
            for (int r = 0; r < 5; ++r) {
                for (int c = 0; c < 5; ++c) {
                    if(hasWord(r,c,word)) result = true;
                }
            }

            if (result) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
    }


    return 0;
}
