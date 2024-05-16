// 1. 무한루프를 돌며 N번쨰 영화 제목을 찾는다 !
// 2. substr(i,2) : i에서 i + 2까지 절삭한다.

#include <iostream>
#include <string>

using namespace std;

int main() {
    int N; cin >> N;

    // numArr에 영화의 제목을 차례차레 넣는다.
    int cnt = 1;
    int num = 666;

    while (true) {
        // N번째 영화 제목 출력!!
        if (cnt == N) {
            cout << num;
            break;
        }

        num += 1;
        string str = to_string(num);
        int len = str.length();
        // 666 찾으면 오케이 !
        for (int i = 0; i < len - 2; ++i) {
            if (str.substr(i,3) == "666") {
                cnt += 1;
                break;
            }
        }
    }


    return 0;
}
