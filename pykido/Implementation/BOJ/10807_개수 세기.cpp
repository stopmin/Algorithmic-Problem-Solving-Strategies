//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 5] 개수 세기 - 바킹독 0x03
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int numArr[N];
    for (int i = 0; i < N; ++i) {
        cin >> numArr[i];
    }

    int v;
    int result = 0;
    cin >> v;

    for (int i = 0; i < N; ++i) {
        if (numArr[i] == v) {
            result += 1;
        }
    }
    cout << result;

    return 0;
}