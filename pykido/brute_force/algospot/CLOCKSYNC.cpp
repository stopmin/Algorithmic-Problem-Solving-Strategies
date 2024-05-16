// [문제 해결의 흐름]
// 1. 스위치를 누르는 순서를 바꾼다고 해서 결과가 바뀌지는 않는다! (누르는 순서와 결과 간의 관계 X)
// 2. 어떤 스위치를 3번 이상 누를 일은 없음 (0~3번 사이! 따라서 전체 경우의 수 : 4**10)
// 3. 그렇다면 0번 스위치부터 9번 스위치까지 0~3번 누르는 경우를 모두 탐색해보자! (사실상 16중 for문 돌리기)
// [TIP]
// 1. 삼항 연산자란? 조건식 ? 반홥값1 : 반환값2
// 2. 함수나 변수는 한 가지 정보를 한 가지 형태로 저장하거나 기능해야함.
// 3.

#include <iostream>
#include <vector>

using namespace std;

int T;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// linked[i][j] = 'x' : i번 스위치와 j번 시계가 연결되어 있다.
// linked[i][j] = '.' : i번 스위치와 j번 시계가 연결되어 있지 않다.
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

// switch번 스위치를 누른다.
void push(vector<int>& clocks, int swtch) {
    // 시계는 16개!
    for (int clock = 0; clock < CLOCKS; ++clock) {
        // swtch와 연결된 시계들은 전부 3시간 앞으로 이동시키기
        if (linked[swtch][clock] == 'x') {
            clocks[clock] += 3;
            if (clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}

// clocks : 현재 시계들의 시침 상태를 나타내는 vector
// swtch : 이번에 누를 스위치의 번호
// 가 주어질 때, 남은 스위치들을 눌러 clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다.
// 만약 불가능하다면 INF 이상의 큰 수를 반환한다.
int solve(vector<int>& clocks, int swtch) {
    // 만약 스위치를 다 눌렀다면 모든 시계가 12시를 가리키고 있다면 0, 아니라면 INF 반환
    if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

    // 이 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지 모두 시도하기
    int result = INF;
    for (int cnt = 0; cnt < 4; ++cnt) { // cnt : 0 (0번 누르기) , 1 (1번 누르기), ..
        result = min(result, cnt + solve(clocks, swtch + 1));
        push(clocks,swtch);
    }

    // push(clocks, swtch)가 네 번 호출되었으니 clocks는 원래와 같은 상태가 된다.
    return result;
}


int main() {
    cin >> T;

    for (int t = 0; t < T; ++t) {
        vector<int> clocks(CLOCKS);

        for (int i = 0; i < CLOCKS; i++) {
            cin >> clocks[i];
        }

        int answer = solve(clocks, 0);
        if(answer == INF) cout  <<  -1  <<  endl;
        else cout   << answer   << endl;
    }




    return 0;
}
