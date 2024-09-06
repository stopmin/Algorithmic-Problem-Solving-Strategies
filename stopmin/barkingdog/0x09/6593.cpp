// 큐를 비우자. break하고 다시 돌리면 어캄? 비워야지.
// Created by 정지민 on 8/28/24.
// https://www.acmicpc.net/problem/6593

#include <bits/stdc++.h>

using namespace std;

struct geocode{
    geocode() {}

    int x;
    int y;
    int z;

    geocode(int x, int y, int z) : x(x), y(y), z(z) {}
};

int dx[6] = {0, 0, 1, 0, 0, -1};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {1, 0, 0, -1, 0, 0};

char board[35][35][35];
int visited[35][35][35];


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int l, r, c; cin >> l >> r >> c;
        if(l==0&&r==0&&c==0) break;

        queue<geocode> Q;
        geocode to;

        memset(visited, 0, sizeof(visited));
        memset(board, ' ', sizeof(board));

        for (int i = 0; i < l; i++)
            for (int j = 0; j < r; j++)
                cin >> board[i][j];

        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    if(board[i][j][k] == 'S') {
                        visited[i][j][k] = 1;
                        Q.push(geocode(i, j, k));
                    }
                    if(board[i][j][k] == 'E') to = geocode(i, j, k);
                }
            }
        }

        bool result = false;
        while(!Q.empty()){
            geocode front = Q.front(); Q.pop();
            if(front.x == to.x && front.y == to.y && front.z == to.z) {
                result = true;
                break;
            }


            for(int dir = 0; dir < 6; dir++){
                int x = front.x + dx[dir];
                int y = front.y + dy[dir];
                int z = front.z + dz[dir];

                if (x < 0 || y < 0 || z < 0 || x >= l || y >= r || z >= c) continue;
                if (visited[x][y][z] != 0 || board[x][y][z] == '#') continue;

                Q.push(geocode(x, y, z));
                visited[x][y][z] = visited[front.x][front.y][front.z] + 1;
            }
        }

        if(result) cout << "Escaped in " << visited[to.x][to.y][to.z] - 1 << " minute(s).\n";
        else cout<< "Trapped!\n";
    }
}
