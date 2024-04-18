#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;

    queue<pair<int,int>> q;

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int n = land.size();
    int m = land[0].size();

    vector<int> oilAmount(m,0);


    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j < m ; j++){
            if(land[i][j] == 1){

                vector<bool> isVisited(m,false);
                int oil = 1;

                q.push(make_pair(j,i));
                land[i][j] = 0;

                isVisited[j] = true;

                while(!q.empty()){
                    pair<int,int> front = q.front();

                    for (int k = 0; k < 4; k++){
                        int x = front.first + dx[k];
                        int y = front.second + dy[k];

                        if (0 <= x && x < m && 0 <= y && y < n && land[y][x] == 1){
                            q.push(make_pair(x, y));
                            isVisited[x] = true;
                            land[y][x] = 0;
                            oil++;
                        }
                    }
                    q.pop();
                }

                for(int c = 0 ; c < m; c++){
                    if(isVisited[c]) oilAmount[c] += oil;
                }

            }

        }
    }

    for (auto entry:oilAmount){
        if(entry > answer){
            answer = entry;
        }
    }

    return answer;
}