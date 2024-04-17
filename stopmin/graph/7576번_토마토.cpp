#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N;
bool hasZero = false;
queue<pair<int,int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0,1,0,-1};

int main() {
    cin >> M >> N;
    vector<vector<int>> tomatoes(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tomato;
            cin>>tomato;
            if (tomato == 1) q.push(make_pair(i, j));
            if(tomato == 0) hasZero = true;
            tomatoes[i][j] = tomato;

        }
    }

    if(!hasZero){
        cout<<"0";
        return 0;
    }

    int answer;
    while (!q.empty()) {
        pair<int,int> front = q.front();
        for (int i = 0; i < 4; i++) {
            if (front.first + dx[i] < N
                && front.first + dx[i] >= 0
                && front.second + dy[i] < M
                && front.second + dy[i] >= 0) {
                int now = tomatoes[front.first + dx[i]][front.second + dy[i]];
                if (now == 0){
                    tomatoes[front.first + dx[i]][front.second + dy[i]] = tomatoes[front.first][front.second] + 1;
                    answer = tomatoes[front.first][front.second];q.push(make_pair(front.first + dx[i], front.second + dy[i]));
                }
            }
        }
        q.pop();
    }


    bool hasZero = [&tomatoes]() -> bool {
        for (const auto& row : tomatoes) {
            for (int elem : row) {
                if (elem == 0) {
                    return true;
                }
            }
        }
        return false;
    }();

    if (hasZero) {
        cout << "-1";
    } else {
        cout << answer;
    }
}
