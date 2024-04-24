//
// 5 -> 4 -> 8 -> 16 -> 17
// 5 -> 10 -> 9 -> 18 -> 17
//
// 1.


#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K; // N : 수빈이의 위치, K : 동생의 위치
bool visited[MAX];
int memo[MAX]; // 연산 과정 저장할 배열
int result; // 동생 찾는 최단 시간
vector<int> ans_vector; //

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(N, 0));

    visited[N] = true;  // 시작 위치 방문 처리

    while (!q.empty()) {
        int curPosition = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[curPosition] = true;

        // 동생 찾았다면??
        if (curPosition == K) {
            result = time;

            int i = curPosition; // 현재 위치 K
            while(i != N) {
                ans_vector.push_back(i);
                i = memo[i]; // i = 이전 위치
            }
            ans_vector.push_back(i);

            break;
        }

        int minusPosition = curPosition - 1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        // 1. -1
        if (minusPosition >= 0 && !visited[minusPosition]) {
            q.push(make_pair(minusPosition,time + 1));
            memo[minusPosition] = curPosition;  // ⭐️ 나중 위치 인덱스가 현재 위치 값을 저장한다 !!
        }

        // 2. + 1
        if (plusPosition < MAX && !visited[plusPosition]){
            q.push(make_pair(plusPosition,time + 1));
            memo[plusPosition] = curPosition;
        }

        // 3. * 2
        if (multiPosition < MAX && !visited[multiPosition]) {
            q.push(make_pair(multiPosition,time + 1));
            memo[multiPosition] = curPosition;
        }
    }

    cout << result << endl;
    for (int i = result + 1; i >= 0; i--) {
        cout << ans_vector[i] << " ";
    }

}

int main() {
    cin >> N >> K; // 입력 받기
    fill_n(visited, MAX, false); // 방문 배열 전부 false로 초기화
    bfs();

    return 0;
}