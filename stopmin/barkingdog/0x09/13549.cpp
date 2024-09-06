// deque를 써보자.
// Created by 정지민 on 9/2/24.
// https://www.acmicpc.net/problem/13549
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int dist[100005];
    memset(dist, -1, sizeof(dist));
    deque<int> dq;

    dist[n] = 0;
    dq.push_front(n);

    while (!dq.empty()) {
        int front = dq.front();
        dq.pop_front();

        if (front == k) {
            cout << dist[front];
            return 0;
        }


        if (front * 2 < 100005 && dist[front * 2] == -1) {
            dist[front * 2] = dist[front];
            dq.push_front(front * 2);
        }

        if (front - 1 >= 0 && dist[front - 1] == -1) {
            dist[front - 1] = dist[front] + 1;
            dq.push_back(front - 1);
        }


        if (front + 1 < 100005 && dist[front + 1] == -1) {
            dist[front + 1] = dist[front] + 1;
            dq.push_back(front + 1);
        }


    }
}
