//
// Created by 정지민 on 8/27/24.
// https://www.acmicpc.net/problem/3986

#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;

    while (n--) {
        stack<char> st;
        string s; cin >> s;

        for(char c:s){
            if(s.empty()){
                st.push(c);
                continue;
            }

            if(!st.empty() && st.top()==c) st.pop();
            else st.push(c);
        }

        if(st.empty()) ans++;
    }
    cout << ans;
}
