//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 3] 핸드폰 요금 - 바킹독 0x01
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int numArr[N];
    int result_Y = 0;
    int result_M = 0;

    for (int i = 0; i  < N; ++i) {
        cin >> numArr[i];
        result_Y += ((numArr[i] / 30) + 1) * 10;
        result_M += ((numArr[i] / 60) + 1) * 15;
    }

    if (result_Y == result_M) {
        cout << 'Y' << " M " << result_Y;
    } else if (result_Y < result_M) {
        cout << "Y " << result_Y;
    } else {
        cout << "M " << result_M;
    }

    return 0;
}