#include <bits/stdc++.h>
using namespace std;

int dist_1[100001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    fill(dist_1, dist_1 + 100001, -1);
    queue<int> Q;
    Q.push(N);
    dist_1[N] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int arr[3] = {cur+1, cur-1, cur*2};
        for (int i: arr) {
            if (i < 0 || i > 100000) continue;
            if (dist_1[i] != -1) continue;
            Q.push(i);
            dist_1[i] = dist_1[cur] + 1;
            if(i == K){
                cout << dist_1[i] << endl;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}
