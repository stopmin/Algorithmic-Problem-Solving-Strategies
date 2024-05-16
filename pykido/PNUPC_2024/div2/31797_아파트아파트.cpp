//
//
//

#include <iostream>
#define MAX 10001

using namespace std;
int arrApartment[MAX] = {}; // 0으로 초기화

int main() {
    // 입력 받기
    int N, M; // N : 아파트 층 수 , M : 참가자 수
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int hand1, hand2;
        cin >> hand1 >> hand2;
        arrApartment[hand1] = i;
        arrApartment[hand2] = i;
    }

    // 아파트 층 수가 참가자 수 2배를 넘길 경우 ? 아파트 층 수는 2*M으로 나눈 나머지이다.
    // 만약 나머지가 0이라면 아파트 층 수는 2*M이다.
    N %= (2*M);
    if (N == 0) N = 2*M;

    // 구현
    int floor = 1;
    for (int i = 1; i < MAX; i++) {
        if (arrApartment[i] != 0) {
            if (floor == N) {
                cout << arrApartment[i];
                break;
            } else {
                floor += 1;
            }
        }
    }

    return 0;
}
