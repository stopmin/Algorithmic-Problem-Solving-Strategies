//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/6549

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        int n;
        long long ans = 0;
        cin >> n;
        if (n == 0) break;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) cin >> heights[i];

        stack<int> s;

        for(int i = 0; i <= n; i++){
            int h = (i == n) ? 0 : heights[i];

            while(!s.empty() && heights[s.top()] > h){
                // 현재 높이가 top보다 작을 경우
                // 스택에서 pop하여 해당 높이의 최대 넓이를 계산한다.
                // 이때 스택의 top 다음 인덱스부터 현재 인덱스까지의 거리가 된다.
                int height = heights[s.top()];
                s.pop();

                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;
                ans = max(ans, (long long) height * width);
            }
            s.push(i);
        }

        cout << ans << '\n';
    }

}