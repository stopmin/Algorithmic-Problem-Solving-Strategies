//
// Created by 태윤맥북 on 6/13/24.
//

#include <iostream>

using namespace std;

int main() {
    int N;
    int size[6];
    int T, P;

    // 입력 받기
    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }
    cin >> T >> P;

    // 첫번째 줄 출력
    int result1 = 0;
    for (int i = 0; i < 6; i++) {
        if (size[i] % T == 0) {
            result1 += size[i] / T;
        } else {
            result1 += size[i] / T + 1;
        }
    }
    cout << result1 << endl;


    // 두번째 줄 출력
    cout << N / P << " " <<  N % P;

    return 0;
}