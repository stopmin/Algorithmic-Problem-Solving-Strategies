#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int count = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (scores[i] >= scores[i + 1]) {
            count += scores[i] - (scores[i + 1] - 1);
            scores[i] = scores[i + 1] - 1;
        }
    }

    cout << count << '\n';

    return 0;
}