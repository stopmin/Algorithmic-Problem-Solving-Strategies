//
// 5 -> 4 -> 8 -> 16 -> 17
// 5 -> 10 -> 9 -> 18 -> 17
//


#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K; // N : 수빈이의 위치, K : 동생의 위치
int visited[MAX] = {}; // 전부 0으로 초기화
int memo[MAX]; // 연산 과정 저장할 배열
vector<int> ans_vector; // 어떻게 이동하는지 저장하는 vector

void bfs() {
    queue<int> q;
    q.push(N);

    while (!q.empty()) {
        int curPosition = q.front();
        q.pop();

        // 동생 찾았다면??
        if (curPosition == K) {
            int i = curPosition; // 현재 위치 K

            while(i != N) {
                ans_vector.push_back(i);
                i = memo[i]; // i = 이전 위치
            }
            ans_vector.push_back(i); // i == N

            break;
        }

        int minusPosition = curPosition - 1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        // 1. -1
        if (minusPosition >= 0 && visited[minusPosition] == 0) {
            q.push(minusPosition);
            memo[minusPosition] = curPosition;  // ⭐️ 나중 위치 인덱스가 현재 위치 값을 저장한다 !!
            visited[minusPosition] = visited[curPosition] + 1;
        }

        // 2. + 1
        if (plusPosition < MAX && !visited[plusPosition]){
            q.push(plusPosition);
            memo[plusPosition] = curPosition;
            visited[plusPosition] = visited[curPosition] + 1;
        }

        // 3. * 2
        if (multiPosition < MAX && !visited[multiPosition]) {
            q.push(multiPosition);
            memo[multiPosition] = curPosition;
            visited[multiPosition] = visited[curPosition] + 1;
        }
    }

    cout << visited[K] << endl; // 최단 시간 출력
    for (int i = visited[K]; i >= 0; i--) { // 이동 과정 공백 포함해서 출력
        cout << ans_vector[i] << " ";
    }

}

int main() {
    cin >> N >> K; // 입력 받기
    bfs();

    return 0;
}