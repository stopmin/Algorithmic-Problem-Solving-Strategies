#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int arr[1001][1001]; int dist[1001][1001];

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
        dist[i][j] = -1;
        if(arr[i][j] == 2){
            q.push({i, j});
            dist[i][j] = 0;
        }
    }

    while (!q.empty()) {
        int _x = q.front().first;
        int _y = q.front().second;

        for (int dir = 0; dir < 4; dir++) {
            int x = _x + dx[dir];
            int y = _y + dy[dir];

            if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1 && arr[x][y] == 1) {
                dist[x][y] = dist[_x][_y] + 1;
                q.push({x, y});
            }
        }
        q.pop();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(arr[i][j] == 0) dist[i][j] = 0;
            cout<<dist[i][j]<<" ";
        }
        cout << "\n";
    }
}