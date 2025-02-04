#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> campus(n);

    for (int i = 0; i < n; ++i) cin >> campus[i];

    int startX, startY;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (campus[i][j] == 'I') {
                startX = i;
                startY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({startX, startY});
    visited[startX][startY] = true;

    int peopleCount = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && campus[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push({nx, ny});

                if (campus[nx][ny] == 'P') peopleCount++;
            }
        }
    }

    if (peopleCount == 0) cout << "TT\n";
    else cout << peopleCount << "\n";
}