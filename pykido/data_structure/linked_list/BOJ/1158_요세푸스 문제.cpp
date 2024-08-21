//
// Created by 태윤맥북 on 8/21/24.
//
// [실버 4] 1158_요세푸스 문제 - 0x04 연결 리스트
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력 받기
    int N, K;
    cin >> N >> K;
    list<int> lst;
    for (int i = 1; i <= N; ++i) {
        lst.push_back(i);
    }

    list<int> result;
    auto cursor = lst.begin();

    while (!lst.empty()) {
        // K-1번 오른쪽으로 이동 (커서를 한 칸씩만 전진시킴)
        for (int j = 1; j < K; ++j) {
            // 리스트 끝에 도달하면 다시 시작으로 돌아가야 함
            cursor++;
            if (cursor == lst.end()) {
                cursor = lst.begin();
            }
        }

        // 커서가 가리키는 요소를 결과에 추가하고 삭제
        result.push_back(*cursor);
        cursor = lst.erase(cursor);

        // erase 후 cursor가 end()일 경우, 리스트 시작으로 돌아가야 함
        if (cursor == lst.end() && !lst.empty()) {
            cursor = lst.begin();
        }
    }

    // 결과 출력 (요세푸스 순열)
    cout << "<";
    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it;
        if (next(it) != result.end()) {
            cout << ", ";
        }
    }
    cout << ">\n";

    return 0;
}