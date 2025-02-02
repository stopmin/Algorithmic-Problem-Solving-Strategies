#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[200001]; // 시간
int parent[200001]; // 경로

void bfs(int start) {
    queue<int> q;
    q.push(start);
    arr[start] = 0;
    parent[start] = -1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == k) return;
        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (next >= 0 && next <= 200000 && arr[next] == -1) {
                arr[next] = arr[curr] + 1;
                parent[next] = curr;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(arr, arr + 200001, -1);
    fill(parent, parent + 200001, -1);

    bfs(n);
    cout << arr[k] << "\n";

    vector<int> path;
    for (int i = k; i != -1; i = parent[i]) path.push_back(i);

    reverse(path.begin(), path.end());

    for (int i : path) cout << i << " ";
}