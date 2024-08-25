//
// Created by 정지민 on 8/25/24.
// https://www.acmicpc.net/problem/2493

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; // 탑의 수
    stack<pair<int,int> > s;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if(s.empty()){
            s.push({i, x});
            cout << "0 ";
        }

        else {
            while(!s.empty()){
                if(s.top().second > x){
                    cout << s.top().first << " ";
                    break;
                } else {
                    s.pop();
                }
            }
        }
        if(s.empty()) cout << "0 ";

        s.push({i, x});
    }

}