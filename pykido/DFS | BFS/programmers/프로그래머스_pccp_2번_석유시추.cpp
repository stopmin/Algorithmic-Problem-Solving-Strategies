// 1. 석유 지도를 탐색하며 석유를 찾는다.
// 2. 석유를 찾았다면 bfs를 통해 석유덩어리의 크기를 파악하고 해당 석유 덩어리를 캘 수 있는 모든 column값을 set에 저장한다.
// 3. bfs 탐색이 끝났다면 열 위치 중에서 어느 위치에서 시추하는 것이 가장 많은 석유를 캘 수 있을지 찾기

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;


struct Coordinate {
    int row; // 행
    int col; // 열
};

// 석유 덩어리 구조체
struct OilBlock {
    set<int> block; // 석유 덩어리의 열 위치
    int volume; // 석유 덩어리의 크기
};

vector<vector<int> > landMap;
int numRows, numCols; // 석유 지도의 행과 열의 개수
bool visited[501][501]; // 방문 여부를 저장하는 배열

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

OilBlock bfs(Coordinate start) {
    queue<Coordinate> q;
    q.push(start);
    set<int> oilPositions;

    int count = 1;  // 석유 개수
    oilPositions.insert(q.front().col); // 석유의 열 위치

    while (!q.empty()) {
        int currRow = q.front().row;
        int currCol = q.front().col;
        q.pop();

        for (int i = 0; i < 4; i++) { // 석유 주위 4방향을 탐색하며 다른 석유 찾기
            int newRow = currRow + dy[i];
            int newCol = currCol + dx[i];

            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && !visited[newRow][newCol] && landMap[newRow][newCol] == 1) { // 범위값 만족하는지 확인하기
                count++;    // 석유 크기 + 1
                visited[newRow][newCol] = true;;
                Coordinate next = {newRow, newCol};
                q.push(next);
                oilPositions.insert(newCol);    // newCol 열에서 석유 발견!!
            }
        }
    }

    OilBlock result;
    result.block = oilPositions;
    result.volume = count;
    return result;
}

int solution(vector<vector<int> > land) {
    numRows = land.size();
    numCols = land[0].size();
    landMap = land;

    fill_n(&visited[0][0], numRows * numCols, false);

    vector<OilBlock> oilBlocks;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (land[i][j] == 1 && !visited[i][j]) {
                Coordinate start = {i, j};
                visited[i][j] = true;
                oilBlocks.push_back(bfs(start));
            }
        }
    }

    int answer[501] = {0};  // 열 위치 정보들
    int maxNum = 0; // 캘 수 있는 가장 많은 석유량
    for (int i = 0; i < oilBlocks.size(); i++) {
        for (auto col : oilBlocks[i].block) {
            answer[col] += oilBlocks[i].volume;
            maxNum = max(answer[col], maxNum);
        }
    }

    return maxNum;
}

int main() {

    return 0;
}
