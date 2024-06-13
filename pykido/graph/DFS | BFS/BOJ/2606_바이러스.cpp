//
// Created by 태윤맥북 on 4/18/24.
//
#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int computer_num, pair_num;
int pair_array[101][101] = {};
bool visited[101];

int bfs() {
    q.push(1);
    visited[1] = true;
    int cnt = 0;

    while(!q.empty()) {
        int val = q.front();
        q.pop();

        for (int i = 0; i <= computer_num; i++) {
            if (pair_array[val][i] == 1 && !visited[i]) {
                q.push(i);
                cnt++;
                visited[i] = true;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> computer_num;
    cin >> pair_num;

    for (int i = 0; i < pair_num; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        pair_array[num1][num2] = 1;
        pair_array[num2][num1] = 1;
    }

    fill_n(&visited[0], computer_num + 1, false);

    cout << bfs();

    return 0;
}