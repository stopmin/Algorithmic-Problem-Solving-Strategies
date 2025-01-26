// https://www.acmicpc.net/problem/15656

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
vector<int> num;
vector<int> used;

void dfs() {
    if (v.size() == m) {
        for (int i: v) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]){
            v.push_back(num[i]);
            dfs();
            v.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    num.resize(n);
    used.resize(n, false);

    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num.begin(), num.end());
    dfs();
}