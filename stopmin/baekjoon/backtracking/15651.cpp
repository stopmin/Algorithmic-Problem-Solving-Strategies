#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> combination;

void dfs() {
    if (combination.size() == M) {
        for (int num: combination) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        combination.push_back(i);
        dfs(); // 다음 숫자
        combination.pop_back();
    }
}

int main() {
    cin >> N >> M;
    dfs();
    return 0;
}