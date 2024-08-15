//
// Created by 정지민 on 8/15/24.
//
#include <bits/stdc++.h>

using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> M >> N;
    int ans = 0;
    int tomato[1001][1001];
    int dist[1001][1001];
    queue<pair<int,int> > Q;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                Q.push(make_pair(i, j));

            } else if (tomato[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }


    while(!Q.empty()){
        pair<int,int> front = Q.front(); Q.pop();
        for (int dir=0;dir<4;dir++){
            int x = front.first + dx[dir];
            int y = front.second + dy[dir];
            if(x < 0 || y < 0 || x >= N || y >= M) continue;
            if( dist[x][y] >= 0) continue;
            Q.push(make_pair(x,y));
            dist[x][y] = dist[front.first][front.second] + 1;
            ans = max(ans,dist[x][y]);
        }
    }


    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if(dist[i][j] == -1) ans = -1;

    cout<<ans;
}