// 15652
// Created by 정지민 on 1/20/25.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

void dfs(int start) {
    if (v.size() == m) {
        for (int i: v) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        v.push_back(i);
        dfs(i); // 다음 숫자
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    dfs(1);
};