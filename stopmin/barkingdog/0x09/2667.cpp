//
// Created by 정지민 on 8/28/24.
// https://www.acmicpc.net/problem/2667

#include <bits/stdc++.h>
using namespace std;

char board[25][25];
bool visited[25][25] = {false,};

queue<pair<int,int>> Q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];

    int ans = 0;
    vector<int> section;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(board[i][j] == '1' && !visited[i][j]){
                Q.push({i, j});
                visited[i][j] = true;
                ans++;
                int size = 1;

                while (!Q.empty()) {
                    pair<int,int> front = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int x = front.first + dx[dir];
                        int y = front.second + dy[dir];

                        if (x < 0 || y < 0 || x >= n || y >= n) continue;
                        if(board[x][y]!='1' || visited[x][y]) continue;
                        Q.push({x, y});
                        visited[x][y] = true;
                        size++;
                    }
                }

                section.push_back(size);
            }

    cout << ans << '\n';
    sort(section.begin(), section.end());
    for(int i: section) cout << i << '\n';
}
