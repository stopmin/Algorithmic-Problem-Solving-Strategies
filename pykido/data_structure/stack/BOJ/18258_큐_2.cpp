//
// Created by 태윤맥북 on 9/3/24.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int data[MAX];
    int head = 0, tail = 0;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        if (str == "push") {
            int n;
            cin >> n;
            data[tail++] = n;
        } else if (str == "pop") {
            if (head == tail) {
                cout << -1 << '\n';
            } else {
                cout << data[head++] << '\n';
            }
        } else if (str == "size") {
            cout << tail - head << '\n';
        } else if (str == "empty") {
            if (head == tail) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (str == "front") {
            if (head == tail) {
                cout << -1 << '\n';
            } else {
                cout << data[head] << '\n';
            }
        } else if (str == "back") {
            if (head == tail) {
                cout << -1 << '\n';
            } else {
                cout << data[tail-1] << '\n';
            }
        }

    }


    return 0;
}