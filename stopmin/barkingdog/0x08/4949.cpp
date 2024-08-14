//
// Created by 정지민 on 8/15/24.
//
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    while (true) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        string s;
        getline(cin,s);
        if (s == ".") break;
        stack<char> st;
        string answer = "yes";

        for (char c: s) {
            if (answer == "no") break;
            if (c == '('){
                st.push(c);
            }
            else if (c==')'){
                if (st.empty()) answer = "no";
                else if (st.top() == '(') st.pop();
                else answer = "no";
            }
            else if (c == '['){
                st.push(c);
            }
            else if (c == ']'){
                if (st.empty()) answer = "no";
                else if (st.top() == '[') st.pop();
                else answer = "no";
            }
        }
        if (!st.empty()) answer = "no";
        cout << answer << "\n";
    }
}