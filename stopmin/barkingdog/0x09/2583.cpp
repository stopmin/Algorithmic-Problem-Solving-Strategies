// 쉽다.
// Created by 정지민 on 8/27/24.
// https://www.acmicpc.net/problem/2583

#include <bits/stdc++.h>
using namespace std;

int board[105][105] = {0,};
bool visited[105][105] = {false,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int,int>> Q;

int ans = 0;
vector<int> section;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k; cin >> m >> n >> k;

    for(int i = 0; i < k; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        for (int x = b; x < d; x++)
            for(int y = a; y < c; y++)
                board[x][y]++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 0 && !visited[i][j]) {
                visited[i][j] = true;
                Q.push({i, j});
                ans++;

                int tmp = 1;

                while(!Q.empty()) {
                    pair<int,int> front = Q.front(); Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int x = front.first + dx[dir];
                        int y = front.second + dy[dir];
                        if (x < 0 || y < 0 || x >= m || y >= n) continue;
                        if(visited[x][y]||board[x][y]!=0) continue;
                        visited[x][y] = true;
                        Q.push({x, y});
                        tmp++;
                    }
                }
                section.push_back(tmp);
            }

        }
    }

    cout<<ans<<'\n';
    sort(section.begin(), section.end());
    for(int i: section) cout<<i<<" ";
}