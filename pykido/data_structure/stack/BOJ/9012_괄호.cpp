//
// Created by 태윤맥북 on 8/22/24.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        string str;
        cin >> str;
        stack<char> S;
        bool flag = true;

        for (char c : str) {
            if (c == '(') {
                S.push(c);
            } else { // c == ')'
                if (S.empty()) {
                    flag = false;
                    break;
                } else {
                    S.pop();
                }
            }
        }

        if (!S.empty()) {
            flag = false;
        }

        if (flag) {
            cout << "YES";
        } else {
            cout << "NO";
        }

        cout << '\n';
    }

    return 0;
}