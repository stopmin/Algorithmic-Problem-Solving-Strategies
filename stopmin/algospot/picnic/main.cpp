#include <iostream>

int C; // 테스트 케이스의 수
int n, m; // 학생 수, 친구 쌍의 수
bool areFriends[10][10] = {false};

int countPairings(bool taken[10]);

using namespace std;
int main() {
    cin>>C;

    while(C--){
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = true;
            areFriends[b][a] = true;
        }

        bool taken[10] = {false};

        cout << countPairings(taken) << endl;

        // arefriends 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                areFriends[i][j] = false;
            }
        }
    }
}

int countPairings(bool taken[10]){
    int firstFree = -1;

    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if(firstFree == -1) return 1;

    int ret = 0;

    for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] =  taken[pairWith]= true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}
