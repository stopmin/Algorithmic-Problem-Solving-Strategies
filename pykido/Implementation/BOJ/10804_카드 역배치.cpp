//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 2] 카드 역배치 - 바킹독 0x01
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int numArr[21];

    for (int i = 1; i <= 20; ++i) {
        numArr[i] = i;
    }

    for (int i = 0; i < 10; ++i) {
        int a, b;
        cin >> a >> b;
        reverse(numArr + a, numArr + b + 1);
    }

    for (int i = 1; i <= 20; ++i) {
        cout << numArr[i] << " ";
    }

    return 0;
}