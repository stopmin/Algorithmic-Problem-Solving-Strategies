// 1. NC3을 하며 합이 가장 큰 경우를 구하자.
// 2. 단, 합은 M 이하!!

#include <iostream>

using namespace std;

int N, M, card[101] = {};
int visited[101] = {};
int result = 0;


// cnt : 뽑은 수, idx를 통해 시간 줄이기 !!
void solve(int idx, int cnt) {
    // 3장 뽑았다면 M 이하인지 확인 후 반환하기
    if (cnt == 3) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (visited[i] == 1) sum += card[i];
        }
        if (sum <= M) {
            result = max(result, sum);
        }
        return;
    }


    // NC3 수행하기
    for (int i = idx; i < N; ++i) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        solve(i + 1, cnt + 1);
        visited[i] = 0;
    }

}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> card[i];
    }

    solve(0, 0);

    cout << result;

    return 0;
}