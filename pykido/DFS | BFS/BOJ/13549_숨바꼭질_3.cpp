//
//
// 5 -> 10 -> 9 -> 18 -> 17 : 2초
// 5 ->  4 -> 8 -> 16 -> 17 : 2초

// 3 -> 4 -> 5 : 2초
// 3 -> 6 -> 5 : 1초

// 2 -> 4 -> 8 -> 7 : 1초
// 2 -> 3 -> 6 -> 7 : 2초

// 1 -> 2 -> 4 -> 8 -> 16 -> 17 : 1초
// 1 -> 2 -> 4 -> 8 -> 16 -> 17 : 2초 (만약 1 -> 2초가 더하기라면)

// 5 -> 4 -> 8 -> 7: 2초
// 5 -> 10 -> 9 -> 8 : 2초

// 1 -> 2 -> 4 -> 8 -> 16 -> 32 : 0초
// 1 -> 2 -> 4 -> 8 -> 16 -> 32 : 1초 (만약 1-> 2초가 더하기라면)

#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
bool visited[MAX];
queue<pair<int, int> > q;

void bfs() {
    q.push(make_pair(N, 0));
    visited[N] = true;
    int result = MAX; // 동생을 찾는 가장 빠른 시간
    bool first_visit = true;

    while (!q.empty()) {
        int cur_position = q.front().first;
        int cur_time = q.front().second;
        q.pop();
        visited[cur_position] = true;

        if (first_visit && cur_position == K) { // 첫 방문
            result = cur_time;
            first_visit = false;
        } else if (!first_visit && cur_position == K && cur_time < result) { // 첫 방문 아닌데 시간 더 적게 나온다면??
            result = cur_time; // 최소 시간 갱신
        } else if (cur_time > result) continue; // 불필요한 탐색은 그만

        int minusPosition = cur_position - 1;
        int plusPosition = cur_position + 1;
        int multiPosition = cur_position * 2;

        if (minusPosition >= 0 && !visited[minusPosition]) {
            q.push(make_pair(minusPosition, cur_time + 1));
        }

        if (plusPosition < MAX && !visited[plusPosition]) {
            q.push(make_pair(plusPosition, cur_time + 1));
        }

        if (multiPosition < MAX && !visited[multiPosition]) {
            q.push(make_pair(multiPosition, cur_time));
        }
    }

    cout << result; // 수빈이가 동생을 찾는 가장 빠른 시간 출력
}

int main() {
    cin >> N >> K;

    fill_n(visited, MAX, false); // false로 초기화

    bfs();

    return 0;
}