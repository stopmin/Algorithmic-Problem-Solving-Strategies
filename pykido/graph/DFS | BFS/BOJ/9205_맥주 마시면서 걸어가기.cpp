//
// Created by 태윤맥북 on 4/15/24.
// 1. 맥주가 20개(full) 있는 상태에서 현재 있는 거리에서 페스티벌까지 거리가 1000 이하면 무조건 도착 가능
// 2. 편의점이 왜 n개가 주어졌을까....?? 사실 페스티벌에서 제일 가까운 편의점을 bfs로 찾아서 그 편의점과 페스티벌 사이의 거리가 1000 이하인지 구하는 문제 아닐까?
//

#include <iostream>
#include <queue>
#include <cmath>    // abs 함수 사용하려고
using namespace std;

// 좌표 구조체 생성
struct coordinate {
    int x;
    int y;
};

bool cnv_visited[101]; // 편의점 방문
coordinate home;
coordinate fest;

// bfs 구현
bool bfs(coordinate conv[100], int n) {
    queue<coordinate> q;
    q.push(home);   // 첫 시작은 집

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if (abs(fest.x - x) + abs(fest.y - y) <= 1000) return true;

        // 현재 위치에서 갈 수 있는 편의점을 전부 큐에 넣음
        for (int i = 0; i < n; i++) {
            if (!cnv_visited[i] && ((abs(conv[i].x - x) + (abs(conv[i].y - y))) <= 1000 )) {  // 아직 방문하지 않았음
                q.push(conv[i]);
                cnv_visited[i] = true; // 방문 처리
            }
        }
    }

    return false;   // 락페 못 갈 경우
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;  // 편의점 개수

        cin >> n;
        cin >> home.x >> home.y;    // 집 좌표 입력 받기
        coordinate conv[101];
        for (int j = 0; j < n; j++) {   // 편의점 좌표 입력 받기
            cin >> conv[j].x >> conv[j].y;
        }
        cin >> fest.x >> fest.y;    // 페스티벌 좌표 입력 받기
        fill_n(cnv_visited, n, false);  // 편의점 방문 여부 전부 false로 초기화시키기

        if (bfs(conv, n)) cout << "happy" << endl;
        else cout << "sad" << endl;
    }

    return 0;
}