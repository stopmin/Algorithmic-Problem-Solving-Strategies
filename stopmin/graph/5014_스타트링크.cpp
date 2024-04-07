#include <iostream>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAXFLOOR 1000001
using namespace std;

queue<int> floors;
vector<bool> visited(MAXFLOOR,false );

int main() {
    FASTIO;

    int f,s,g,u,d;
    int answer = 0;
    bool reachable = false;
    cin >> f >> s >> g >> u >> d;

    floors.push(s);
    while (!floors.empty()) {
        queue<int> nextQueue;

        while (!floors.empty()) {
            int now = floors.front();
            visited[now] = true;
            floors.pop();

            if (now == g) {
                reachable = true;
                break;
            }
            else {
                if (now + u <= f && u != 0 && !visited[now + u]) {
                    nextQueue.push(now + u);
                    visited[now + u] = true;
                }
                if (now - d >= 1 && d != 0 && !visited[now - d]){
                    nextQueue.push(now - d);
                    visited[now - d] = true;
                }
            }
        }

        swap(floors, nextQueue);


        if (reachable) break;
        answer++;
    }
    if(reachable) cout << answer;
    else cout << "use the stairs";
}
