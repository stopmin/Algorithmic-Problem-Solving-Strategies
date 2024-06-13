//
// Created by 태윤맥북 on 6/13/24.
//

#include <iostream>
#include <string>

using namespace std;

int determine(string str) {
    try {
        int num = stoi(str);
        return num;
    } catch (invalid_argument) {
        return -1;
    }
}

void outputResult(int num){
    if (num % 3 == 0 && num % 5 == 0) {
        cout << "FizzBuzz";
    } else if (num % 3 == 0) {
        cout << "Fizz";
    } else if (num % 5 == 0){
        cout << "Buzz";
    } else {
        cout << num;
    }
}

int main() {
    int nextNum;

    for (int i = 0; i < 3; i++) {
        string inputStr;
        cin >> inputStr;
        int determineNum = determine(inputStr);

        if (determineNum != -1) {
            nextNum = determineNum + 1 + (2-i);
        }
    }

    outputResult(nextNum);

    return 0;
}
