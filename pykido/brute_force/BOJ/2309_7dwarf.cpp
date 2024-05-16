// 1. 난쟁이 9명 중 7명을 뽑는다. (by 조합)
// 2. 7명의 키 합이 100인지 확인한다.
// 3. 100이라면 출력해주기

#include <iostream>
#include <algorithm>

using namespace std;

int visited[9] = {}; // 전부 0으로 초기화
int height[9];

// 찾았다면 키 오름차순으로 출력
void print() {
    for (int i = 0; i < 9; ++i) {
        if (visited[i] == 1) {
            cout << height[i] << endl;
        }
    }
}

// 찾은 7명의 난쟁이들의 키 합이 100인지 확인
void sum_100() {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        if (visited[i] == 1) {
            sum += height[i];
        }
    }

    if (sum == 100) {
        print();
        exit(0); // 합이 100이 되는 조합을 찾았으면 프로그램 종료
    }
}

// cnt : 뽑힌 난쟁이 수
void solve(int idx, int cnt) {
    if (cnt == 7) {
        sum_100();
        return;
    }

    for (int i = idx; i < 9; ++i) {
        if (visited[i] == 1) continue;
        // 백트래킹
        visited[i] = 1;
        solve(i + 1, cnt + 1);
        visited[i] = 0;
    }
}


int main() {
    // 입력 받기
    for (int i = 0; i < 9; ++i) {
        cin >> height[i];
    }

    // 오름차순 정렬
    sort(height, height + 9);

    // 9C7
    solve(0,0);

    return 0;
}