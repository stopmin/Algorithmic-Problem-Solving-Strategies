//
// Created by 정지민 on 8/15/24.
//

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void) {
    int N, M;
    cin >> N >> M;
    string map[N]; // 1: 이동할 수 있는 칸, 0: 이동할 수 없는 칸
    int dist[102][102];

    for (int i = 0 ; i < N; i++)
        cin>>map[i];
    queue<pair<int,int> > Q;
    Q.push(make_pair(0,0));
    map[0][0] = '0';
    while(!Q.empty()){
        pair<int,int> front = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int x = front.X + dx[dir];
            int y = front.Y + dy[dir];
            if(x<0 || y<0||x>=N | y>=M)continue;
            if(map[x][y] != '1' || dist[x][y] > 0) continue;
            Q.push(make_pair(x, y));
            dist[x][y] = dist[front.X][front.Y]+1;
        }
    }
    cout<<dist[N-1][M-1] + 1;
}
