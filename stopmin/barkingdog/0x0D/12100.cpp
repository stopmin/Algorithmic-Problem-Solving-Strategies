//
// Created by 정지민 on 8/18/24.
//
#include <bits/stdc++.h>

using namespace std;
int N;
int board[21][21];
int board2[21][21];
int ans = 0;


void upd(int dir, int dest[21][21]) {
    memset(board2, 0, sizeof(board2));

    for (int i = 0; i < N; i++) {
        vector<int> line;
        for (int j = 0; j < N; j++) {
            int value = (dir % 2 == 1) ? dest[i][j] : dest[j][i];
            if (value != 0) line.push_back(value);
        }

        if (dir == 0 || dir == 3) reverse(line.begin(), line.end());

        vector<int> newLine;
        for (int k = 0; k < line.size(); k++) {
            if (k + 1 < line.size() && line[k] == line[k + 1]) {
                newLine.push_back(line[k] * 2);
                k++;
            } else {
                newLine.push_back(line[k]);
            }
        }

        while (newLine.size() < N) newLine.push_back(0);

        if (dir == 0 || dir == 3) reverse(newLine.begin(), newLine.end());

        for (int j = 0; j < N; j++) {
            if (dir % 2 == 1) board2[i][j] = newLine[j];
            else board2[j][i] = newLine[j];
        }
    }

    memcpy(dest, board2, sizeof(board2));

}


void func(int cur, int current_board[21][21]) {
    if (cur == 5) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, current_board[i][j]);
        return;
    }
    int temp_board[21][21];
    for (int i = 0; i < 4; i++) {
        memcpy(temp_board, current_board, sizeof(temp_board));
        upd(i, temp_board);
        func(cur + 1, temp_board);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    func(0, board);
    cout << ans;
}