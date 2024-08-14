//
// Created by 정지민 on 8/15/24.
//

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    list<char> L;
    string init;
    cin >> init;
    for (auto c: init) L.push_back(c);
    auto cursor = L.end();
    int M;
    cin >> M;

    while (M--) {
        char op;
        cin >> op;

        if (op == 'P') {
            char c;
            cin >> c;
            L.insert(cursor, c);
        } else if (op == 'L') {
            if (cursor != L.begin()) cursor--;
        } else if (op == 'D') {
            if (cursor != L.end()) cursor++;
        } else if (op == 'B') {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }

    for (auto c: L) cout << c;
}