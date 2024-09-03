//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 2] 숫자 - 바킹독 0x01
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    if (A < B) {
        // 두 수 사이에 있는 정수의 개수를 출력
        cout << B - A - 1 << '\n';

        // 두 수 사이의 정수를 오름차순으로 출력
        for (long long i = A + 1; i < B; ++i) {
            cout << i << " ";
        }
    } else if (A > B){
        // 두 수 사이에 있는 정수의 개수를 출력
        cout << A - B - 1 << '\n';

        // 두 수 사이의 정수를 오름차순으로 출력
        for (long long i = B + 1; i < A; ++i) {
            cout << i << " ";
        }
    } else {
        cout << 0;
    }



    return 0;
}