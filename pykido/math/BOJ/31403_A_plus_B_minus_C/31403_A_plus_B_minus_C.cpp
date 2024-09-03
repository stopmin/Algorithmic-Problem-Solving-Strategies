//
// Created by 태윤맥북 on 6/13/24.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;

    cout << stoi(A) + stoi(B) - stoi(C) << endl;

    cout << stoi(A + B) - stoi(C) << endl;


    return 0;
}
