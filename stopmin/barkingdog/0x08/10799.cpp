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

    stack<char> st;
    bool laser = false;
    for (char c: s) {
        if (c == '(') {
            st.push(c);
            laser = false;
        } else {
            if (!laser) {
                st.pop();
                ans += st.size();
                laser = true;
            } else {
                ans++;
                st.pop();
            }
        }
    }


    cout << ans;
}