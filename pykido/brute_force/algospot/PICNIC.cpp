// 종만북 p.155 소풍 (문제 ID : PICNIC, 난이도 : 하)
// 1. 중복으로 세는 문제 해결하기 (firstStudent 변수를 통해 가능한 조합을 오름차순으로 정렬)
// 2. 2차원 배열을 통해 짝 표시
// 3. for문에서 i++보다 ++i 사용하자. (더욱 효율적임)
//  (1) i++ : i의 값을 보관. i에 1을 더함. i값 반환
//  (2) ++i : i의 값에 1을 더함. i값 반.
// 4. 조합 계산이기에 백트래킹해주기!!
//  백트래킹 : 알고리즘 기법 중 하나로 재귀적으로 문제를 해결하되 해를 찾는 도중 해가 절대 될 수 없다고 판단되면, 되돌아가서 다시 해를 찾는다고 생각하면 된다.
//  백트래킹 예제 (1) 조합적 문제 : 주어진 조건에 따라 가능한 모든 조합을 찾아야 할 때 백트래킹을 사용 (외판원 문제, N-queen 문제)
//             (2) 제약 충족 문제 : 주어진 제약 조건을 만족하는 해를 찾아야 할 때 백트래킹을 사용 (스도쿠 문제, 매직 스퀘어 문제)

#include <iostream>
#include <cstring>

using namespace std;

bool areFriends[10][10];

int C;
int n, m; // n : 학생 수 , m : 친구 쌍의 수
bool taken[10];

// taken[i] : i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int countPairings(bool taken[10]) {
    // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
    int firstStudent = -1;
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            firstStudent = i;
            break;
        }
    }

    // 기저 사례 : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
    if (firstStudent == - 1) return 1;
    int result = 0;

    // firstStudent와 짝지을 학생을 결정한다.
    for (int pairWith = firstStudent + 1; pairWith < n; ++pairWith) {
        if (!taken[pairWith] && areFriends[pairWith][firstStudent]) {
            // 백트래킹
            taken[firstStudent] = taken[pairWith] = true;
            result += countPairings(taken);
            taken[firstStudent] = taken[pairWith] = false;
        }
    }

    return result;
}



int main() {
    cin >> C;

    for (int i = 0; i < C; ++i) {
        // 배열 초기화
        memset(areFriends, false, sizeof(areFriends));
        memset(taken, false, sizeof(taken));

        // 입력 받기
        cin >> n >> m;
        for (int j = 0; j < m; ++j) {
            int friend1, friend2;
            cin >> friend1 >> friend2;
            areFriends[friend1][friend2] = areFriends[friend2][friend1] = true;
        }

        cout << countPairings(taken) << endl;
    }


    return 0;
}