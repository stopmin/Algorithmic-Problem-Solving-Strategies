#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

int n, m, v;
vector<int> graph[MAX];
bool visited[MAX] = {false};

void dfs(int start) {
    visited[start] = true;
    cout << start << " ";

    // Sort the neighbors in ascending order
    sort(graph[start].begin(), graph[start].end());

    for (int i = 0; i < graph[start].size(); i++) {
        int y = graph[start][i];
        if (!visited[y]) {
            dfs(y);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    bool visited[MAX] = {false};

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        // Sort the neighbors in ascending order
        sort(graph[x].begin(), graph[x].end());

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int k, l;
        cin >> k >> l;
        graph[k].push_back(l);
        graph[l].push_back(k);
    }

    dfs(v);
    cout << endl;
    bfs(v);

    return 0;
}
