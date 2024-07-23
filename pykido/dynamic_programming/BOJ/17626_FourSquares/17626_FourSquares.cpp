//
// Created by 태윤맥북 on 7/23/24.
//

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    // 1. 입력 받기
    int n;
    cin >> n;

    // 2. bottom-up
    int dp[50001] = {};
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + 1;

        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i],dp[i-j*j] + 1);
        }
    }

    // 3. 출력
    cout << dp[n];

    return 0;
}