#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> combination;

void dfs(int start) {
    if (combination.size() == M) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        combination.push_back(i);
        dfs(i + 1); // 다음 숫자 선택
        combination.pop_back(); // 백트래킹
    }
}

int main() {
    cin >> N >> M;
    dfs(1); // 1부터 시작
    return 0;
}