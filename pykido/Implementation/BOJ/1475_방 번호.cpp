//
// Created by 태윤맥북 on 8/20/24.
//
// [실버 5] 방 번호 - 바킹독 0x03
#include <iostream>

using namespace std;

int main() {
    string N;
    cin >> N;

    int numArr[10] = {0};

    for (int i = 0; i < N.length(); ++i) {
        if (N[i] == '9') {
            N[i] = '6';
        }
        numArr[N[i] - '0'] += 1;
    }
    numArr[6] = numArr[6] / 2 + numArr[6] % 2;

    int result = numArr[0];
    for (int i = 1; i < 10; ++i) {
        result = max(result, numArr[i]);
    }

    cout << result;

    return 0;
}