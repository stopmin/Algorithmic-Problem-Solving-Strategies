//
// Created by 태윤맥북 on 9/2/24.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    stack<pair<int, int> > S;
    for (int i = 0; i < N; ++i) {
        int curHeight;
        cin >> curHeight;

        while(!S.empty()) {
            if (curHeight < S.top().first) {
                cout << S.top().second << " ";
                S.push(make_pair(curHeight, i+1));
                break;
            }
            S.pop();
        }

        if (S.empty()) {
            cout << "0 ";
            S.push(make_pair(curHeight, i+1));
        }

    }


    return 0;
}