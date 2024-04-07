#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <algorithm>
#define MAX_STEP 1000
using namespace std;

bool available(pair<int, int> &first, pair<int, int> &second){
    return abs(first.first - second.first) + abs(first.second - second.second)<=MAX_STEP;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int N;
        bool isHappy = false;
        queue<int> q;

        cin >> N;

        vector<pair<int, int>> location(N + 2);
        vector<bool> visited(N + 2, false);

        for (int i = 0; i < N + 2; i++) {
            int x, y;
            cin >> x >> y;
            location[i].first = x;
            location[i].second = y;
        }

        pair<int, int> festival = location[N + 1];

        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int now = q.front();
            if (available(festival, location[now])) {
                isHappy = true;
                break;
            }

            for (int i = 0 ; i < N + 2; i++) {
                if (available(location[now], location[i]) && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
            q.pop();
        }
        if (isHappy) cout << "happy" << endl;
        else cout << "sad" << endl;
    }
}
