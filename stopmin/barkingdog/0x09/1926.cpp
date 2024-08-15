//
// Created by 정지민 on 8/15/24.
//

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int pic[n][m];
    queue<pair<int, int> > q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int cnt = 0;
    int s = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pic[i][j];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pic[i][j] == 0) continue;
            pic[i][j] = 0;
            cnt++;
            q.push(make_pair(i, j));
            int temp_s = 0;
            while (!q.empty()) {
                pair<int, int> front = q.front();
                temp_s++; // 넓이 쁠쁠
                pic[front.first][front.second] = 0;
                for (int d = 0; d < 4; d++) {
                    int x = front.first + dx[d];
                    int y = front.second + dy[d];
                    if (0 > x || 0 > y || x >= n || y >= m) {
                        continue;
                    }
                    else if (pic[x][y] == 1) {
                        q.push(make_pair(x, y));
                        pic[x][y] = 0;
                    }
                }
                q.pop();
            }
            if (temp_s > s) s = temp_s;
        }
    }

    cout << cnt << "\n" << s << endl;
}