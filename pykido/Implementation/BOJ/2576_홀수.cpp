//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 3] 홀수 - 바킹독 0x01

#include <iostream>

using namespace std;

int main() {
    int totalOddNum = 0;
    int minOddNum = 101;
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            totalOddNum += num;
            minOddNum = min(minOddNum, num);
        }
    }
    if (minOddNum == 101) {
        cout << -1;
    } else {
        cout << totalOddNum << '\n';
        cout << minOddNum;
    }

    return 0;
}