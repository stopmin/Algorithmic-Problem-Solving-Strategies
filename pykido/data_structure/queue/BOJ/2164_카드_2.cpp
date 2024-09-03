//
// Created by 태윤맥북 on 9/3/24.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    queue<int> q;
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop();
        int n = q.front();
        q.push(n);
        q.pop();
    }

    cout << q.front();

    return 0;
}