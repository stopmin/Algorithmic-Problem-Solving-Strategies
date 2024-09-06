// 별로 어렵지 않음.
// Created by 정지민 on 8/27/24.
// https://www.acmicpc.net/problem/7562

#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int visited[300][300] = {0,};
        int l; cin >> l;
        pair<int, int> from; cin >> from.first >> from.second;
        pair<int, int> to; cin >> to.first >> to.second;

        queue<pair<int,int>> Q;

        Q.push({from.first, from.second});

        while(!Q.empty()){
            pair<int,int> front = Q.front(); Q.pop();
            if(front.first == to.first && front.second == to.second) break;

            for(int dir = 0; dir < 8; dir++){
                int x = front.first + dx[dir];
                int y = front.second + dy[dir];

                if(x<0 || y<0|| x >= l || y >= l) continue;
                if(visited[x][y] != 0) continue;
                Q.push({x, y});
                visited[x][y] = visited[front.first][front.second] + 1;
            }
        }

        cout<<visited[to.first][to.second]<<endl;
    }
}

