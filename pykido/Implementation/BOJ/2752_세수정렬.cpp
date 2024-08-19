//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 4] 세수 정렬 - 바킹독 0x01

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    sort(num, num + 3);

    cout << num[0] << " " << num[1] << " " << num[2];

    return 0;
}