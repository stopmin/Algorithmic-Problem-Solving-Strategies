//
// Created by 태윤맥북 on 6/19/24.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > v_schedule;

int main() {
    // 1. 입력 받기
    cin >> N;
    int begin, end;
    for (int i = 0; i < N; i++) {
        cin >> begin >> end;
        v_schedule.push_back(make_pair(end,begin));
    }

    // 2. 구현
    // 종료시간 순으로 오름차순 정렬
    sort(v_schedule.begin(), v_schedule.end());

    // '현재 스케쥴 종료시간 <= 그다음 스케쥴 시작'이라면 스케쥴 새로 갱신
    int cnt = 1;
    int time = v_schedule[0].first;
    for (int i = 1; i < N; ++i) {
        if (time <= v_schedule[i].second) {
            time = v_schedule[i].first;
            cnt += 1;
        }
    }

    cout << cnt << '\n';

    return 0;
}