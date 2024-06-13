//
//
//

#include <iostream>

using namespace std;

int N;
int arrNum[101];
int visited[101] = {};
int result = 0;
int arrResult[101] = {};

// num : 현재 숫자, target : 타겟 숫자
void dfs(int num, int target) {
    if (arrNum[num] == target) {
        arrResult[result] = target;
        result += 1;
    } else {
        if (visited[arrNum[num]] == 0) {
            visited[arrNum[num]] += 1;
            dfs(arrNum[num], target);
            visited[arrNum[num]] -= 1;
        }
    }
}

int main() {
    // 입력 받기
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        arrNum[i] = num;

    }

    // dfs 돌리기
    for (int i = 1; i <= N; i++) {
        dfs(i,i);
    }

    // 출력하기
    cout << result << endl;
    for (int i = 0; i < result; i++) {
        cout << arrResult[i] << endl;
    }
    return 0;
}
