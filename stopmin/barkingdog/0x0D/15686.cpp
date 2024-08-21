#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;
bool isused[20];
int s[100][100]; // i: 집, j: 치킨집
int ans = 1000000000;


void func(int idx, int selected){
    if(selected == M){
        int total_dist = 0;
        for(int i = 0; i < house.size(); i++) {
            int min_dist = 1000000000;
            for(int j = 0; j < chicken.size(); j++) {
                if(isused[j])
                    min_dist = min(min_dist, s[i][j]);
            }
            total_dist += min_dist;
        }
        ans = min(ans, total_dist);
        return;
    }
    if(idx == chicken.size()) return;

    isused[idx] = true;
    func(idx + 1, selected + 1);
    isused[idx] = false;

    func(idx + 1, selected);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int c;
            cin >> c;
            if (c == 1) house.push_back({i, j});
            else if (c == 2) chicken.push_back({i, j});
        }
    }

    for (int i = 0; i < house.size(); i++) {
        for (int j = 0; j < chicken.size(); j++) {
            s[i][j] = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
        }
    }

    func(0,0);
    cout<<ans;
}