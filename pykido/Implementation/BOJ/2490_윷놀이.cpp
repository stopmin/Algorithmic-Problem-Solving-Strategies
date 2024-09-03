//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 3] 윷놀이 - 바킹독 0x01

#include <iostream>

using namespace std;

int yut[3][4];
char result[5] = {'E','A','B','C','D'};

int main() {
    for (int r = 0; r < 3; ++r) {
        int index = 0;
        for (int c = 0; c < 4; ++c) {
            cin >> yut[r][c];
            if (yut[r][c] == 0) {
                index += 1;
            }
        }
        cout << result[index] << '\n';
    }

    return 0;
}
