#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> S;
    long long result = 0;
    for (int i = 0; i < N; ++i) {
        int curHeight;
        cin >> curHeight;

        while(!S.empty()) {
            if (S.top() > curHeight) {
                result += S.size();
                S.push(curHeight);
                break;
            }
            S.pop();
        }

        if (S.empty()) {
            S.push(curHeight);
        }
    }

    cout << result;

    return 0;
}