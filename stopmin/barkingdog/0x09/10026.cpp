//
// Created by 정지민 on 8/27/24.
// https://www.acmicpc.net/problem/10026

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    char picture[100][100];
    bool dict1[100][100] = {false,};
    bool dict2[100][100] = {false,};


    for (int i = 0; i < n; i++)
        cin >> picture[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            queue<pair<int,int>> Q;
            if (!dict1[i][j]) {
                Q.push({i, j});
                dict1[i][j] = true;
                cnt++;
            }

            while (!Q.empty()) {
                pair<int,int> front = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int x = front.first + dx[dir];
                    int y = front.second + dy[dir];

                    if(x < 0 || y < 0 | x >= n || y >= n) continue;
                    if(!dict1[x][y] && (picture[front.first][front.second] == picture[x][y])){
                        dict1[x][y] = true;
                        Q.push({x, y});
                    }
                }
            }
        }
    }
    cout << cnt << " ";


    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            queue<pair<int,int>> Q;
            if (!dict2[i][j]) {
                Q.push({i, j});
                dict1[i][j] = true;
                cnt2++;
            }

            while (!Q.empty()) {
                pair<int,int> front = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int x = front.first + dx[dir];
                    int y = front.second + dy[dir];

                    if(x < 0 || y < 0 | x >= n || y >= n) continue;
                    if(!dict2[x][y]){
                        char cur = picture[front.first][front.second];
                        if(cur == 'B' && cur == picture[x][y]) {
                            dict2[x][y] = true;
                            Q.push({x, y});
                        }
                        if((cur=='R' || cur=='G') && (picture[x][y]=='R' || picture[x][y]=='G')){
                            dict2[x][y] = true;
                            Q.push({x, y});
                        }
                    }
                }
            }
        }
    }

    cout << cnt2;
}
