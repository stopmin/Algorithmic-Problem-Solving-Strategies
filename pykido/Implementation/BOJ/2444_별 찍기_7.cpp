//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 3] 별 찍기 7 - 바킹독 0x01

#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N*2 - 1; ++i) {
        if (i <= N) {
            for (int j = 0; j < N-i; ++j) {
                cout << " ";
            }
            for (int j = 0; j < 2*i - 1; ++j) {
                cout << "*";
            }
        } else {
            for (int j = 0; j < i-N; ++j) {
                cout << " ";
            }
            for (int j = 0; j < 2*(2*N - i) - 1; ++j) {
                cout << "*";
            }
        }
        cout << "\n";
    }


    return 0;
}
