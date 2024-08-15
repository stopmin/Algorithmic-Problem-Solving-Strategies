//
// Created by 정지민 on 8/15/24.
//

#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int R, C; // R: 열, C:행
string board[1001];
int jihoon[1001][1001];
int fire[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;

    for (int i = 0 ; i<R;i++){
        fill(jihoon[i], jihoon[i]+C , -1);
        fill(fire[i], fire[i]+C , -1);
        cin >> board[i];
    }

    queue<pair<int, int> > jihoon_Q;
    queue<pair<int, int> > fire_Q;


    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'J') {
                jihoon_Q.push(make_pair(i, j));
                jihoon[i][j] = 0;
            } else if (board[i][j] == 'F') {
                fire_Q.push(make_pair(i, j));
                fire[i][j] = 0;
            }
        }
    }

    while (!fire_Q.empty()) {
        auto fire_front = fire_Q.front(); fire_Q.pop();
        for (int i = 0; i < 4; i++) {
            int x = fire_front.first + dx[i];
            int y = fire_front.second + dy[i];
            if (x < 0 || y < 0 || x >= R || y >= C) continue;
            if (fire[x][y] >= 0 || board[x][y] == '#') continue;
            fire[x][y] = fire[fire_front.first][fire_front.second] + 1;
            fire_Q.push(make_pair(x, y));
        }
    }

    while (!jihoon_Q.empty()) {
        auto jihoon_front = jihoon_Q.front(); jihoon_Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int x = jihoon_front.first + dx[dir];
            int y = jihoon_front.second + dy[dir];
            if (x < 0 || y < 0 || x >= R || y >= C){
                cout<<jihoon[jihoon_front.first][jihoon_front.second]+1;
                return 0;
            }
            if (board[x][y] == '#' || jihoon[x][y] >= 0) continue;
            if (fire[x][y] != -1 && jihoon[jihoon_front.first][jihoon_front.second]+1 >= fire[x][y]) continue;
            jihoon[x][y] = jihoon[jihoon_front.first][jihoon_front.second]+1;
            jihoon_Q.push(make_pair(x, y));
        }
    }

    cout<<"IMPOSSIBLE";
}
