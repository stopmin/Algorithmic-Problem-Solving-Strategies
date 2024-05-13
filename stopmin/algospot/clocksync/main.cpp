#include <iostream>
#include <vector>

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
using namespace std;

// linked[i][j] = 'x' : 스위치 i가 시계 j에 연결되어 있다.
const char linked[SWITCHES][CLOCKS + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

// 모든 시계가 12시를 가리키고 있는지 확인
bool areAligned(const vector<int>& clocks) {
    for (int i = 0; i < CLOCKS; i++) {
        if (clocks[i] != 12) {
            return false;
        }
    }
    return true;
}

void push(vector<int>& clocks, int swtch) {
    for (int i = 0; i < CLOCKS; i++) {
        if (linked[swtch][i] == 'x') {
            clocks[i] += 3;
            if (clocks[i] == 15) {
                clocks[i] = 3;
            }
        }
    }
}

int solve(vector<int>& clocks, int swtch) {
    if (swtch == SWITCHES) { // 10번째 스위치까지 누름
        return areAligned(clocks) ? 0 : INF;
    }

    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++) { // 스위치를 0번부터 3번까지 누름
        ret = min(ret, cnt + solve(clocks, swtch + 1)); // 다음 스위치를 누른다.
        push(clocks, swtch); // 현재 스위치를 누른다.
    }

    return ret;
}



int main() {
    int C;
    cin >> C;

    while (C--) {
        vector<int> clocks(CLOCKS);
        for (int i = 0; i < CLOCKS; i++) {
            cin >> clocks[i];
        }
        int answer = solve(clocks, 0);
        if(answer == INF) cout<<-1<<endl;
        else cout<<answer<<endl;
    }
}
