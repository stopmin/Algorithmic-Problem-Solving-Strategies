//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 2] 대표값2 - 바킹독 0x01
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int numArr[5];
    int totalNum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> numArr[i];
        totalNum += numArr[i];
    }

    cout << totalNum/5 << '\n';

    sort(numArr, numArr+5);
    cout << numArr[2];


    return 0;
}