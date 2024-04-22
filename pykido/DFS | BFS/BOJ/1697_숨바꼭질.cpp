//
//

#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K; // N : 수빈이의 위치, K : 동생의 위치
int visited[MAX] = {};

int bfs() {
    queue<int> q;
    q.push(N);
    visited[N] = 0;
    while (!q.empty()) {
        int curPosition = q.front();
        q.pop();

        if (curPosition == K) break;

        int minusPosition = curPosition - 1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        // 1. -1
        if (minusPosition >= 0 && visited[minusPosition] == 0) {
            q.push(minusPosition);
            visited[minusPosition] = visited[curPosition] + 1;
        }

        // 2. + 1
        if (plusPosition < MAX && visited[plusPosition] == 0){
            q.push(plusPosition);
            visited[plusPosition] = visited[curPosition] + 1;
        }

        // 3. * 2
        if (multiPosition < MAX && visited[multiPosition] == 0) {
            q.push(multiPosition);
            visited[multiPosition] = visited[curPosition] + 1;
        }
    }

    return visited[K];
}

int main() {
    cin >> N >> K;
    cout << bfs();

    return 0;
}
