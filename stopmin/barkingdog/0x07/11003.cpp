//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/11003
#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(const pair<int,int>&a, const pair<int,int>&b){
        if(a.second != b.second) return a.second > b.second; // 실제 값 기준
        else return a.first > b.first; // 인덱스 기준
    }
};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;

    int n, l; cin >> n >> l;

    for(int i=0; i<n; i++){
        int val; cin >> val;

        pq.push({i, val});
        while(pq.top().first <= i - l) pq.pop();

//        cout << pq.top().second << ' ';
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
    }
}
