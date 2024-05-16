// 1. N까지 부분합을 구하며 부분합이 N인 경우를 찾는다.
// 2. 몫 연산자 : /, 나머지 연산자 : %

#include <iostream>

using namespace std;

int main() {
    int N, result = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int num = i, constructor = i;

        // 한 자릿수까지 계속 나누기
        while (num/10) {
            constructor += num % 10;
            num /= 10;
        }
        // 일의 자릿수 더해주기
        constructor += num;

        // 생성자 찾음!
        if (constructor == N) {
            result = i;
            break;
        }
    }

    cout << result;

    return 0;
}
