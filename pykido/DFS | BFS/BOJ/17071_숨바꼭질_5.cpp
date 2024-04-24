//
//
// 1. 입력 17 5를 위해 방문 처리를 해주지 않았더니 메모리 초과가 발생하였다 ㅠㅠ.. 사실 모든 bfs 문제는 방문처리를 해줘야 한다. 그렇지 않으면 queue에 지수 제곱만큼 메모리가 쌓이기 때문...
// 2. 그래서 나는 반례를 분석해 보았다. 예를 들어 입력이 16 50일 때 정답이 5라고 하는데.. 무슨 수를 써서라도 16에 5번의 연산을 거쳐 65를 못 만든다!!
// 그러다가 1.에서의 추억이 떠올랐다. 아!!!! 순간이동하지 않고 계속 왔다 갔다할 수도 있지 않을까? 그러니깐 5초 후에

#include <iostream>
#include <queue>
using namespace std;

#define MAX 500001

int N, K; // N : 수빈이의 위치, K : 동생의 위치
int visited[2][MAX] = {}; // 전부 0으로 초기화

struct val {
    int position;
    int time;
    int K_val;
};

int bfs() {
    queue<val> q;
    val first_val = {N,0,K}; // [시작] 위치 : N, 시간 : 0, K의 값 : K
    q.push(first_val);
    visited[0][N] = 1;
    int flag;

    while (!q.empty()) {
        int curPosition = q.front().position;;
        int curTime = q.front().time;
        int curK = q.front().K_val;
        q.pop();

        if (curK >= MAX) return -1; // 아직 못 찾았다면 -1

        if (visited[curTime%2][curK] == 1) return curTime; // 이전에 찾은 적이 있다면 현재 시간 출력

        if (curTime%2 == 0) flag = 1; // 현재 시간은 짝순데 저장되는 값은 홀수
        else flag = 0;               // 현재 시간은 홀순데 저장되는 값은 짝수


        int minusPosition = curPosition - 1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        curK += curTime + 1;

        // 1. -1
        if (minusPosition >= 0 && visited[flag][minusPosition] == 0) {
            val minus_val = {minusPosition, curTime + 1, curK};
            q.push(minus_val);
            visited[flag][minusPosition] = 1;
        }

        // 2. + 1
        if (plusPosition < MAX && visited[flag][plusPosition] == 0) {
            val plus_val = {plusPosition, curTime + 1, curK};
            q.push(plus_val);
            visited[flag][plusPosition] = 1;
        }

        // 3. * 2
        if (multiPosition < MAX && visited[flag][multiPosition] == 0) {
            val multi_val = {multiPosition, curTime + 1, curK};
            q.push(multi_val);
            visited[flag][multiPosition] = 1;
        }
    }
    return -1;

}

int main() {
    cin >> N >> K; // 입력 받기
    if (N == K) cout << 0;
    else cout << bfs();

    return 0;
}