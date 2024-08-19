//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 2] 방 배정 - 바킹독 0x03
#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int student[6][2] = {0,};
    int roomNum = 0;

    for (int i = 0; i < N; ++i) {
        int S, Y;
        cin >> S >> Y;
        if (student[Y-1][S] == 0) {
            roomNum += 1;
            student[Y-1][S] += 1;
        } else {
            student[Y-1][S] += 1;
            if (student[Y-1][S] > K) {
                roomNum += 1;
                student[Y-1][S] -= K;
            }
        }
    }

    cout << roomNum;

    return 0;
}