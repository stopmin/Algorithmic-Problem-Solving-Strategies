//
// Created by 정지민 on 8/15/24.
//

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<int> de;

    int N;
    cin >> N;
    while (N--) {
        string oper;
        cin >> oper;

        if (oper == "push_back") {
            int i;
            cin >> i;
            de.push_back(i);
        } else if (oper == "push_front") {
            int i;
            cin >> i;
            de.push_front(i);
        } else if (oper == "front") {
            if (de.empty()) cout << "-1\n";
            else cout << de.front() << "\n";
        } else if (oper == "back") {
            if (de.empty()) cout << "-1\n";
            else cout << de.back() << "\n";
        } else if (oper == "pop_front") {
            if (de.empty()) cout << "-1\n";
            else {
                cout << de.front() << "\n";
                de.pop_front();
            }
        } else if (oper == "pop_back") {
            if (de.empty()) cout << "-1\n";
            else {
                cout << de.back() << "\n";
                de.pop_back();
            }
        } else if (oper == "empty") {
            if (de.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (oper == "size") {
            cout << de.size() << "\n";
        }

    }
}
