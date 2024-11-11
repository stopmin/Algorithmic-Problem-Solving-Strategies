// 조건이 짜증난다.
// Created by 정지민 on 8/27/24.
// https://www.acmicpc.net/problem/5427

#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

char place[1005][1005];
int dict1[1005][1005]; // 상근이
int dict2[1005][1005]; // 불

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;

        memset(place, 0, sizeof(place));
        memset(dict1, 0, sizeof(dict1));
        memset(dict2, 0, sizeof(dict2));


        queue<pair<int, int>> Q1; // 상근이
        queue<pair<int, int>> Q2; // 불

        // 시작 위치, 불 위치
        for (int i = 0; i < h; i++) cin >> place[i];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (place[i][j] == '*') {
                    Q2.push({i, j});
                    dict2[i][j] = 1;
                } else if (place[i][j] == '@') {
                    Q1.push({i, j});
                }
            }
        }


        // 불 먼저 채우기
        while (!Q2.empty()) {
            pair<int, int> front = Q2.front();
            Q2.pop();

            for (int dir = 0; dir < 4; dir++) {
                int x = front.first + dx[dir];
                int y = front.second + dy[dir];

                if (x < 0 || y < 0 || x >= h || y >= w) continue;
                if ((place[x][y] == '.' || place[x][y] == '@') && dict2[x][y] == 0) {
                    Q2.push({x, y});
                    dict2[x][y] = dict2[front.first][front.second] + 1;
                }
            }
        }

        // 상근이가 달려나간다.
        bool result = false;
        while (!Q1.empty()) {
            pair<int, int> front = Q1.front();
            Q1.pop();
            if (front.first == 0 || front.first == h - 1 || front.second == 0 || front.second == w - 1) {
                result = true;
                cout << dict1[front.first][front.second] + 1 << '\n';
                break;
            }

            for (int dir = 0; dir < 4; dir++) {
                int x = front.first + dx[dir];
                int y = front.second + dy[dir];

                if (x < 0 || y < 0 || x >= h || y >= w) continue;
                if (place[x][y] == '.' && dict1[x][y] == 0 &&
                    (dict2[x][y] - 2 > dict1[front.first][front.second] || dict2[x][y] == 0)) {

                    Q1.push({x, y});
                    dict1[x][y] = dict1[front.first][front.second] + 1;
                }
            }
        }


        if (!result) cout << "IMPOSSIBLE\n";
    }
}