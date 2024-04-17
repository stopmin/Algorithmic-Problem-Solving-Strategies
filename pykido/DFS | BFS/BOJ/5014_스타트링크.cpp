#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int visited[1000001] = {};
queue<int> q;

// bfs로 구현
int bfs() {
    visited[S] = 1;
    q.push(S);

    while (!q.empty()) {
        int now = q.front(); // 현재 층
        q.pop(); // front 삭제
        if (now == G) return visited[G]; // 도달했다면

        int go_up = now + U;    // 올라간다면
        int go_down = now - D;  // 내려간다면

        // 올라갈 수 있나?
        if (go_up <= F && !visited[go_up]) {
            visited[go_up] = visited[now] + 1;
            q.push(go_up);
        }

        // 내려갈 수 있나?
        if (go_down >= 1 && !visited[go_down]) {
            visited[go_down] = visited[now] + 1;
            q.push(go_down);
        }
    }

    // 엘리베이터로 이동할 수 없을 때
    return -1;
}

int main() {
    cin >> F >> S >> G >> U >> D;

    int result = bfs();

    if (result == -1) cout << "use the stairs";
    else cout << result - 1; // 버튼 누른 횟수를 반환해야하니 1을 빼줘야한다.


    return 0;
}