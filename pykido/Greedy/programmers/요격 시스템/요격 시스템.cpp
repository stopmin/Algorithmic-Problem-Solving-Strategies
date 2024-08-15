#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > targets) {
    int answer = 0;

    // 1. 2차원 벡터의 2번째 요소를 오름차순으로 정렬
    sort(targets.begin(), targets.end(), [&](vector<int> &v1, vector<int> &v2) {
        return v1[1] < v2[1];
    });

    // 2. 행의 길이 구하기
    int rows = targets.size();

    // 3. 사실 폭격 미사일의 범위가 겹치는 애들끼리는 무조건 같이 처리할 수 있다!!!
    int cur_x = 0;

    for (int i = 0; i < rows; i++) {
        if (cur_x <= targets[i][0]) {
            answer++;
            cur_x = targets[i][1];
        }
    }

    return answer;
}