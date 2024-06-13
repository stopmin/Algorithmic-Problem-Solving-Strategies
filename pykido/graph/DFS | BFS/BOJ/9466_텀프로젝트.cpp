
#include <iostream>
#include <cstring>
#define MAX 100001

using namespace std;

int arrStudent[MAX];
bool visited[MAX]; // 방문 처리
bool done[MAX]; // 팀을 이미 구해서 더 이상 볼 일 없음
int result; // 팀에 속하는 사람들 구하기


void dfs(int current) {
    visited[current] = true;    // 방문 처리해주기

    if (!visited[arrStudent[current]]) { // 방문한 적 없다면
        dfs(arrStudent[current]);
    } else if (!done[arrStudent[current]]) { // 처음 보는 사이클이라면?
        for (int i = arrStudent[current]; i != current; i = arrStudent[i]) { // 백트래킹
            result += 1;
        }
        result += 1; // 자기 자신도 세주기
    }

    done[current] = true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        // 입력 받기
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> arrStudent[j];
        }

        // 초기화
        result = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof done);

        // dfs 실행
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                dfs(j);
            }
        }

        // 출력하기
        cout << n - result << endl;
    }

    return 0;
}
