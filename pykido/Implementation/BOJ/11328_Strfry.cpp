//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 2] Strfry - 바킹독 0x03
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N;
    cin >> N;

    string str1, str2;
    int alphabetArr[26];
    bool isPossible;

    for (int i = 0; i  < N; ++i) {
        cin >> str1 >> str2;
        memset(alphabetArr, 0, sizeof(alphabetArr));
        isPossible = true;

        for (int j = 0; j < str1.length(); ++j) {
            alphabetArr[str1[j] - 'a']++;
            alphabetArr[str2[j] - 'a']--;
        }

        for (int j = 0; j  < 26; ++j) {
            if (alphabetArr[j] != 0) {
                isPossible = false;
                break;
            }
        }

        if (isPossible) {
            cout << "Possible" << '\n';
        } else {
            cout << "Impossible" << '\n';
        }
    }




    return 0;
}