#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans = 10000;
int place[9][9];
int isVisible[9][9];
vector<pair<int, int> > cctv;
int dx[] = {-1, 0, 1, 0}; // 위, 오른쪽, 아래, 왼쪽
int dy[] = {0, 1, 0, -1};

void updateVisibility(int x, int y, int direction, bool add) {
    int nx = x + dx[direction];
    int ny = y + dy[direction];

    while (nx >= 0 && nx < N && ny >= 0 && ny < M && place[nx][ny] != 6) {
        if (place[nx][ny] == 0) {
            if (add) {
                isVisible[nx][ny]++;
            } else {
                isVisible[nx][ny]--;
            }
        }
        nx += dx[direction];
        ny += dy[direction];
    }
}

void cctv1(int x, int y, int dir, bool add) {
    updateVisibility(x, y, dir, add);
}

void cctv2(int x, int y, int dir, bool add) {
    updateVisibility(x, y, dir, add);
    updateVisibility(x, y, (dir + 2) % 4, add); // 반대 방향
}

void cctv3(int x, int y, int dir, bool add) {
    updateVisibility(x, y, dir, add);
    updateVisibility(x, y, (dir + 1) % 4, add); // 직각 방향
}

void cctv4(int x, int y, int dir, bool add) {
    updateVisibility(x, y, dir, add);
    updateVisibility(x, y, (dir + 1) % 4, add);
    updateVisibility(x, y, (dir + 2) % 4, add); // 세 방향
}

void cctv5(int x, int y, bool add) {
    for (int dir = 0; dir < 4; dir++) {
        updateVisibility(x, y, dir, add); // 네 방향 모두
    }
}

void func(int idx) {
    if (idx == cctv.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (place[i][j] == 0 && isVisible[i][j] == 0)
                    cnt++;
        ans = min(ans, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int num = place[x][y];

    for (int dir = 0; dir < 4; dir++) {
        if (num == 1) cctv1(x, y, dir, true);
        else if (num == 2 && dir < 2) cctv2(x, y, dir, true); // 2번은 수평/수직만
        else if (num == 3) cctv3(x, y, dir, true);
        else if (num == 4) cctv4(x, y, dir, true);
        else if (num == 5) {
            cctv5(x, y, true);
            func(idx + 1);
            cctv5(x, y, false);
            return;
        }

        func(idx + 1);

        if (num == 1) cctv1(x, y, dir, false);
        else if (num == 2 && dir < 2) cctv2(x, y, dir, false);
        else if (num == 3) cctv3(x, y, dir, false);
        else if (num == 4) cctv4(x, y, dir, false);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> place[i][j];
            if (place[i][j] >= 1 && place[i][j] <= 5) {
                cctv.push_back(make_pair(i, j));
            }
        }
    }

    func(0);
    cout << ans << endl;
}
