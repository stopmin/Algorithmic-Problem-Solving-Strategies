//
//
//

#include <iostream>
#define MAX 101

using namespace std;

int N; // 무기의 수
int X, S; // X : 돈, S : 후안의 공격력
int weaponPower, weaponPrice;

int main() {
    cin >> N;
    cin >> X >> S;
    bool result = false;

    for (int i = 0; i < N; i++) {
        cin >> weaponPrice >> weaponPower;
        if (weaponPrice <= X && weaponPower > S) {
            result = true;
            break;
        }
    }

    if (result) cout << "YES";
    else cout << "NO";

    return 0;
}

