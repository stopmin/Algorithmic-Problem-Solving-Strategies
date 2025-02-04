#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int count[200001] = {0,};
    int fruit; int type = 0; int ans = 0;


    for (int i = 0; i < n; i++) {
        cin >> fruit;
        if (count[fruit] == 0) {
            type++;
        }
        count[fruit]++;
        q.push(fruit);

        while (type > 2) {
            int front = q.front();
            q.pop();
            count[front]--;
            if (count[front] == 0) {
                type--;
            }
        }

        ans = max(ans, (int)q.size());
    }
    cout << ans;
}