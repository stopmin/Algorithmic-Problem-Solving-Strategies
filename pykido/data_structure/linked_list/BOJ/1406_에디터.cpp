//
// Created by 태윤맥북 on 8/21/24.
//
// [실버 2] 1406_에디터 - 0x04 연결 리스트
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력 받기
    string str;
    cin >> str;
    int M;
    cin >> M;

    // 연결 리스트화
    list<char> lst;
    for (auto c : str) lst.push_back(c);

    auto cursor = lst.end();
    while (M--) {
        char op;
        cin >> op;

        if (op == 'L') { // 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
            if (cursor != lst.begin()) {
                cursor--;
            }
        } else if (op == 'D') { // 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
            if (cursor != lst.end()) {
                cursor++;
            }
        } else if (op == 'B') { // 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
                                // 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
            if (cursor != lst.begin()) {
                cursor = lst.erase(--cursor);
            }
        } else if (op == 'P') { // $라는 문자를 커서 왼쪽에 추가함
            char value;
            cin >> value;
            lst.insert(cursor, value);
        }
    }
    for (auto c : lst) cout << c;

    return 0;
}