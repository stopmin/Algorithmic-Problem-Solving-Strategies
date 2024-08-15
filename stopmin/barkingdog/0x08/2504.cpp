//
// Created by 정지민 on 8/15/24.
//
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);
    int ans = 0;
    int temp = 1;
    char pre;

    stack<char> st;

    for (char c: s) {
        if (c == '(') {
            st.push(c);
            temp *= 2;
        } else if (c == '[') {
            st.push(c);
            temp *= 3;
        } else if (c == ')') {
            if (st.empty() || st.top() == '[') {
                ans = 0;
                break;
            }
            st.pop();

            if (pre == '(') {
                ans += temp;
                temp /= 2;
            } else {
                temp /= 2;
            }


        } else if (c == ']') {
            if (st.empty() || st.top() == '(') {
                ans = 0;
                break;
            }
            st.pop();
            if (pre == '[') {
                ans += temp;
                temp /= 3;
            } else {
                temp /= 3;
            }

        }
        pre = c;
    }

    if (!st.empty()) cout << "0" << endl;
    else cout << ans;
}