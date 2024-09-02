//
// Created by 태윤맥북 on 8/28/24.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> S;
    int tmp = 0;
    int result = 0;
    for (char c : str) {
        if (c == '(') {
            S.push('(');
            tmp += 1;
        } else {
            // c == ')'
            if (S.top() == '(') {
                tmp -= 1;
                result += tmp;
                S.push(')');
            } else {
                // c == ')'
                tmp -= 1;
                result += 1;
                S.push(')');
            }
        }
    }

    cout << result;

    return 0;
}