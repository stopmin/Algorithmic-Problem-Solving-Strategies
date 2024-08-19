//
// Created by 태윤맥북 on 8/19/24.
//
// [브론즈 2] 애너그램 만들기 - 바킹독 0x03
#include <iostream>

using namespace std;

int main() {
    string eng_word1, eng_word2;
    cin >> eng_word1;
    cin >> eng_word2;
    int alphabetArr[26] = {0};

    for (int i = 0; i < eng_word1.length(); ++i) {
        alphabetArr[eng_word1[i] - 'a']++;
    }
    for (int i = 0; i < eng_word2.length(); ++i) {
        alphabetArr[eng_word2[i] - 'a']--;
    }

    int result = 0;
    for (int i = 0; i < 26; i++) {
        if (alphabetArr[i] > 0) {
            while (alphabetArr[i] != 0) {
                alphabetArr[i] -= 1;
                result += 1;
            }
        } else if (alphabetArr[i] < 0) {
            while (alphabetArr[i] != 0) {
                alphabetArr[i] += 1;
                result += 1;
            }
        }
    }

    cout << result;

    return 0;
}