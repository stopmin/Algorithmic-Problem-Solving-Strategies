//
// Created by 정지민 on 8/29/24.
// https://www.acmicpc.net/problem/2573

#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> Q;
int n, m;

bool visited[305][305] = {false,};
int board[305][305];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


bool bfs(int x) {
    memset(visited, false, sizeof(visited));
    int componentCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] >= x && !visited[i][j]) {
                componentCount++;
                if (componentCount >= 2) return true;  // 두 개 이상의 덩어리가 생기면 종료

                Q.push({i, j});
                visited[i][j] = true;

                while(!Q.empty()) {
                    pair<int, int> front = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = front.first + dx[dir];
                        int ny = front.second + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(visited[nx][ny] || board[nx][ny] < x) continue;
                        Q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }
    return false;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int x = 1; x <= 10; x++) {
        if (bfs(x)) {
            cout << x - 1 << '\n';
            return 0;
        }
    }

    cout << "0\n";
}