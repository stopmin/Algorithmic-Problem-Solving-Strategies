//
// Created by 정지민 on 8/28/24.
// https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>
using namespace std;

int n;

int board[105][105] = {0,};
bool visited[105][105] = {false,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int num){
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> Q;
    int ans = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] > num && !visited[i][j]) {
                Q.push({i, j});
                visited[i][j] = true;
                ans++;

                while(!Q.empty()) {
                    pair<int,int> front = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int x = dx[dir] + front.first;
                        int y = dy[dir] + front.second;
                        if(x < 0 || y < 0 || x >= n || y >= n) continue;
                        if(board[x][y] <= num || visited[x][y]) continue;
                        Q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
    return ans;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int ans = 0;
    for(int i=0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    for (int i = 0; i <= 100; i++)
        ans = max(ans, bfs(i));

    cout << ans;
}