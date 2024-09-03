//
// Created by 태윤맥북 on 9/3/24.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<pair<int, int> > S;
    int cnt_same_height = 0;
    long long result = 0;
    int curHeight;
    for (int i = 0; i < N; ++i) {
        cin >> curHeight;
        cnt_same_height = 1;

        while (!S.empty() && S.top().first < curHeight) { // (1) S.top().first < curHeight
            result += S.top().second;
            S.pop();
        }

        if (!S.empty()) {
            if (S.top().first == curHeight) { // (2) S.top().first == curHeight
                result += S.top().second;
                cnt_same_height = (S.top().second + 1);
                if (S.size() > 1) result++;

                S.pop();
            } else { // (3) S.top().first > curHeight
                result++;
            }
        }

        S.push(make_pair(curHeight, cnt_same_height));
    }

    cout << result;


    return 0;
}