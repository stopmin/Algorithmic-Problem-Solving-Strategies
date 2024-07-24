#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {0,0,0,0};

    // 최대 노드 번호를 찾습니다.
    int maxNode = 0;
    for (const auto& entry : edges) {
        maxNode = max(maxNode, max(entry[0], entry[1]));
    }

    // 그래프를 빈 벡터로 초기화합니다.
    vector<vector<int>> graph(maxNode + 1);
    vector<vector<int>> reversedGraph(maxNode+1);

    for (const auto& entry : edges) {
        graph[entry[0]].push_back(entry[1]);
        reversedGraph[entry[1]].push_back(entry[0]);
    }

    int total = 0;
    for (int i = 1 ; i < reversedGraph.size(); i++){
        if (reversedGraph[i].size() == 0 && graph[i].size() >= 2){
            answer[0] = i;
            total = graph[i].size();
        }
        else if (reversedGraph[i].size()>=2 && graph[i].size()==2){
            answer[3]++;
        }
        else if (reversedGraph[i].size()>=1 && graph[i].size()==0){
            answer[2]++;
        }


    }
    answer[1] = total-answer[3]-answer[2];
    return answer;
}