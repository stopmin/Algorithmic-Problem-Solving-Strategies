#include <iostream>
#include <queue>
#define MAX_DISTANCE  100001
using namespace std;

int N, K;

queue<int> q;
vector<int> road(MAX_DISTANCE, 0);

int answer = MAX_DISTANCE;
int answerCount = 0;

void compareAndPush(int cost, int x){
    if (road[x] == 0 || road[x] == cost + 1) {
        road[x] = cost + 1;
        q.push(x);
    }

    if (x == K) {
        answerCount++;
        answer = cost;
    }
}

int main(){
    cin >> N >> K;
    if (N == K) cout << 0 << "\n" << 1 << endl;
    else {
        q.push(N);

        while (!q.empty()) {
            int front = q.front();
            int cost = road[front];

            if (cost > answer) break;
            if (front + 1 < MAX_DISTANCE) compareAndPush(cost, front + 1);
            if (front - 1 >= 0 ) compareAndPush(cost, front - 1);
            if (front * 2 < MAX_DISTANCE) compareAndPush(cost, front * 2);

            q.pop();
        }
        cout << answer + 1 << endl;
        cout << answerCount << endl;
    }
}