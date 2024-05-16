// 최근 김동혁 박사는 아레시보 전파망원경에서 star Vega로부터 수신한 전파 기록의 일부를 조사하여 그 전파들의 패턴을 분석하여 아래와 같이 기록
//(100+1+ | 01)+
// 예제 1 : 1001 01 11
// 예제 2 : 01 10001 00110001
// 예제 3 : 01 10001 01 1001

#include <iostream>
#include <string>

#define endl '\n'

using namespace std;

bool recursive(string str) {
    bool flag = false;
    int size = str.size();

    // 패턴 발견!!
    if (size == 0) return true;

    // 01
    if (str[0] == '0') {
        if (str[1] == '1') flag |= recursive(str.substr(2)); // 01자르고 반복 (flag = flag | 재귀함수)
    }
    // 100+1+
    else if (str[0] == '1') {
        // 0+ 구간
        int index_0 = 1;
        while (index_0 < size && str[index_0] == '0') {
            ++index_0;
        }
        if (index_0 <= 2) { // 0이 적어도 2개
            return flag;
        }

        // 1 구간
        int index_1 = index_0;
        while (index_1 < size && str[index_1] == '1') {
            ++index_1;
        }
        // 1이 1개
        if (index_1 == index_0 + 1) flag |= recursive(str.substr(index_1));
        // 1이 2개 이상일 때 마지막 1 뒤에 0 개수 확인
        if (index_1 >= index_0 + 2) {
            if (index_1 == size - 1) return flag;
            if (index_1 + 1 < size && str[index_1 + 1] == '0')
                flag |= recursive(str.substr(index_1-1));
            else
                flag |= recursive(str.substr(index_1));
        }
    }

    return flag;
}
int main() {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        string input; cin >> input;
        string answer = (recursive(input)) ? "YES" : "NO";
        cout << answer << endl;
    }
    return 0;
}