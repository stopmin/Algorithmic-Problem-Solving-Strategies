//
// Created by 태윤맥북 on 4/18/24.
//

#include <iostream>
#include <queue>

using namespace std;

long long A, B;
queue<pair<long long, long long> > q;

int bfs() {
    q.push(make_pair(A, 1));

    while (!q.empty()) {
        long long val = q.front().first;
        long long cnt = q.front().second;
        q.pop();

        if (val == B) return cnt;

        long long mul_2 = val * 2;
        long long pl_1 = val * 10 + 1;

        if (mul_2 <= B) {
            q.push(make_pair(mul_2, cnt + 1));
        }

        if (pl_1 <= B) {
            q.push(make_pair(pl_1, cnt + 1));
        }
    }

    return -1;
}

int main() {
    cin >> A >> B;
    cout << bfs();

    return 0;
}