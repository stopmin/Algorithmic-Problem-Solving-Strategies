#include <iostream>
#include <vector>
using namespace std;

vector<string> board(5,"");

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool inRange(int y, int x){
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

bool hasWord(int y, int x, const string &word){
    if (!inRange(y,x)) return false;
    if (board[y][x] != word[0]) return false;
    if (word.size() == 1) return true;

    for (int direction = 0; direction < 8; direction++) {
        int nextY = y + dy[direction];
        int nextX = x + dx[direction];
        if (hasWord(nextY, nextX, word.substr(1))) {
            return true;
        }
    }
    return false;
}

bool hasAnswer(const string &word){
    for (int by = 0; by < 5; by++) {
        for (int bx = 0; bx < 5; bx++) {
            if(hasWord(by, bx, word)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int C,N;
    cin >> C;

    while(C--) {
        for (int i = 0; i < 5; i++) {
            cin >> board[i];
        }

        cin >> N;
        vector<string> word(N, "");

        for (int i = 0; i < N; i++) {
            cin >> word[i];
        }

        for (const auto &entry: word) {
            if(hasAnswer(entry)) cout<<entry<<" YES"<<endl;
            else cout<<entry<<" NO"<<endl;
        }
    }
}
