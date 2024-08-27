//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/18258

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    int n;
    cin >> n;

    while(n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (op == "front") {
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        } else if (op == "back") {
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        } else if (op == "size") {
            cout << q.size() << '\n';
        } else if (op == "pop") {
            if(q.empty()) cout << "-1\n";
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (op == "empty") {
            cout << q.empty() << '\n';
        }
    }
}
