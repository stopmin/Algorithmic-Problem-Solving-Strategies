// 1. 단순히 최단 시간을 구하는 문제이기에 방문 배열에 시간을 갱신해주자.
// 2. 물통에 물을 가득 채우는 경우, 물통에 물을 비우는 경우, 물을 다른 물통으로 옮기는 경우가 A, B에 대해 총 6가지 존재한다. 모든 경우를 bfs로 탐색하자.
// 3. 탐색하다가 종료조건을 만나면 최단 시간을 반환해주자.
// 문제 구현은 완벽했던 거 같지만 visited[10만][10만] 배열을 사용하면 메모리 초과가 발생하였다 ㅠㅠ.. 그렇기에 map을 사용하였다.

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int a, b, c, d;

int bfs() { // 매개변수로 변수를 받도록 수정
    map<pair<int, int>, int> visited; // map으로 visited 선언 (전부 0으로 초기화됨)
                                      // pair<int, int>를 키로, int를 값으로 사용

    queue<pair<int, int> > q;
    q.push(make_pair(0,0));    // 처음엔 물통 비어있음
    visited[make_pair(0, 0)] = 1; // 초기 상태 방문 표시

    while (!q.empty()) {
        int cur_A = q.front().first;
        int cur_B = q.front().second;
        q.pop();

        if (cur_A == c && cur_B == d) return visited[make_pair(cur_A, cur_B)] - 1; // 목표 달성 시 종료

        // 1. 물통에 물을 가득 채운다.
        // (1) F(A)
        if (visited[(make_pair(a, cur_B))] == 0) {
            q.push(make_pair(a,cur_B));
            visited[make_pair(a, cur_B)] = visited[make_pair(cur_A, cur_B)] + 1;
        }
        // (2) F(B)
        if (visited[(make_pair(cur_A, b))] == 0) {
            q.push(make_pair(cur_A,b));
            visited[make_pair(cur_A, b)] = visited[make_pair(cur_A, cur_B)] + 1;
        }

        // 2. 물통을 비운다.
        // (1) E(A)
        if (visited[(make_pair(0, cur_B))] == 0) {
            q.push(make_pair(0,cur_B));
            visited[make_pair(0, cur_B)] = visited[make_pair(cur_A, cur_B)] + 1;
        }
        // (2) E(B)
        if (visited[make_pair(cur_A, 0)] == 0) {
            q.push(make_pair(cur_A,0));
            visited[make_pair(cur_A, 0)] = visited[make_pair(cur_A, cur_B)] + 1;
        }

        // 3. 물통의 물을 옮긴다. (단, 물통의 최대 용량까지만!!)
        int pour;
        // (1) M(cur_A, cur_B)
        pour = min(cur_A, b - cur_B); // 옮길 수 있는 물의 양
        if (visited[make_pair(cur_A - pour,cur_B + pour)] == 0) {
            q.push(make_pair(cur_A - pour, cur_B + pour));
            visited[make_pair(cur_A - pour, cur_B + pour)] = visited[make_pair(cur_A, cur_B)] + 1;
        }
        // (2) M(cur_B, cur_A)
        pour = min(cur_B, a - cur_A); // 옮길 수 있는 물의 양
        if (visited[make_pair(cur_A + pour, cur_B - pour)] == 0) {
            q.push(make_pair(cur_A + pour, cur_B - pour));
            visited[make_pair(cur_A + pour, cur_B - pour)] = visited[make_pair(cur_A, cur_B)] + 1;
        }
    }

    return -1;
}

int main() {
    cin >> a >> b >> c >> d;

    cout << bfs();

    return 0;
}
