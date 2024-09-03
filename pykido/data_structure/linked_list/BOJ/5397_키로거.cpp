//
// Created by 태윤맥북 on 8/21/24.
//
// [실버 2] 5397_키로커 - 0x04 연결 리스트
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string password;
        cin >> password;

        // 양방향 linked list
        list<char> lst;
        auto cursor = lst.begin(); // 처음부터 확인해보자!!

        for (auto c : password) {
            if (c == '<') { // 커서 왼쪽으로 - 1
                if (cursor != lst.begin()) {
                    cursor--;
                }
            } else if (c == '>') { // 커서 오른쪽으로 + 1
                if (cursor != lst.end()) {
                    cursor++;
                }
            } else if (c == '-') { // 백스페이스
                if (cursor != lst.begin()) {
                    cursor = lst.erase(--cursor); // 현재 위치에서 왼쪽으로 한 칸 이동 후 요소 삭제
                }
            } else {
                lst.insert(cursor, c); // cursor 위치에 c값을 넣고 cursor는 오른쪽으로 한 칸 이동!
            }
        }

        // 출력하기
        for (auto c : lst) {
            cout << c;
        }
        cout << '\n';
    }


    return 0;
}