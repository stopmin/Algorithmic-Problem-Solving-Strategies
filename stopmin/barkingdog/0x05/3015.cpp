//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/3015

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<pair<int, int>> s; // 키, 개수
    long long ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        // 더 큰게 들어올 경우
        while (!s.empty() && s.top().first < height) {
            ans += s.top().second;
            s.pop();
        }
        if (s.empty()) s.push({height, 1});
        else {
            // 같은게 들어올경우
            if (s.top().first == height) {
                int cur = s.top().second;
                s.pop();

                if(!s.empty()) ans++; // 남아있는 사람이 있는 경우 더 큰 키의 사람과 마주볼 수 있는 쌍은 오직 한 번만 발생하기 때문이다.
                ans += cur;

                s.push({height, cur + 1});
            }
            else { // 더 작은게 들어올 경우
                ans += 1;
                s.push({height, 1});
            }
        }
    }

    cout << ans;
}