//
// 5 -> 4 -> 8 -> 16 -> 17
// 5 -> 10 -> 9 -> 18 -> 17
//
// 1. '1697_숨바꼭질'과 방문처리를 다르게 해주어야 한다.
// 2. 이전 문제는 동생을 찾는 최단 시간을 찾는 문제지만 이번 문제는 최단 시간 및 최단 시간이 같은 방법들을 더 찾아야 하기 때문이다.
// 3. 그렇기에 queue에 (현재 위치, 지금까지 걸린 시간)을 저장하고 q.pop()되는 시점에 방문처리해준다. q.pop() 이전에 방문처리해준다면 방법은 무조건 하나뿐!
// 4. ⭐️ 첫 방문일 경우 최단 시간을 저장해주자! 이후 최단 시간과 같은 방법일 경우 방법 + 1, 최단 시간보다 큰 경우 break를 통해 탐색을 종료한다.
//

#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K; // N : 수빈이의 위치, K : 동생의 위치
bool visited[MAX];
int wayNum = 0;

void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(N, 0));
    visited[N] = true;  // 시작 위치 방문 처리
    bool first_visit = true;
    int fasted_time = MAX; // 수빈이가 동생을 찾는데 걸린 최소 시간

    while (!q.empty()) {
        int curPosition = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[curPosition] = true;

        // 동생 찾았다면??
        if ((curPosition == K) && first_visit) { // 첫 방문
            wayNum += 1;
            fasted_time = time;
            first_visit = false;
        } else if (!first_visit && curPosition == K && time == fasted_time){ // 첫 방문 X
            wayNum += 1;
        } else if (time > fasted_time) break; // 불필요한 탐색은 더 이상 그만


        int minusPosition = curPosition - 1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        // 1. -1
        if (minusPosition >= 0 && !visited[minusPosition]) {
            q.push(make_pair(minusPosition, time + 1));
        }

        // 2. + 1
        if (plusPosition < MAX && !visited[plusPosition]){
            q.push(make_pair(plusPosition, time + 1));
        }

        // 3. * 2
        if (multiPosition < MAX && !visited[multiPosition]) {
            q.push(make_pair(multiPosition, time + 1));
        }
    }

    cout << fasted_time << endl;
    cout << wayNum;
}

int main() {
    cin >> N >> K; // 입력 받기
    fill_n(visited, MAX, false); // 방문 배열 전부 false로 초기화
    bfs();

    return 0;
}