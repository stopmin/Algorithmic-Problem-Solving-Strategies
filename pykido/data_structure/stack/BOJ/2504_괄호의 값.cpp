//
// Created by 태윤맥북 on 8/28/24.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> S;
    int result = 0, tmp = 1;
    for (int idx = 0; idx < str.length(); ++idx) {
        if (str[idx] == '(') { // (1) case '('
            tmp *= 2;
            S.push('(');
        } else if (str[idx] == ')') { // (2) case ')'
            if (S.empty() || S.top() != '(') { // 잘못된 입력
                result = 0;
                break;
            }
            if (str[idx-1] == '(') {
                result += tmp;
                tmp /= 2;
                S.pop();
            } else {
                tmp /= 2;
                S.pop();
            }
        } else if (str[idx] == '[') { // (3) case '['
            tmp *= 3;
            S.push('[');
        } else if (str[idx] == ']') { // (4) case ']'
            if (S.empty() || S.top() != '[') {
                result = 0;
                break;
            }
            if (str[idx-1] == '[') {
                result += tmp;
                tmp /= 3;
                S.pop();
            } else {
                tmp /= 3;
                S.pop();
            }
        }
    }

    if (!S.empty()) result = 0;

    cout << result;


    return 0;
}