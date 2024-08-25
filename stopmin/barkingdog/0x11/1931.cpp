//
// Created by 정지민 on 8/25/24.
// https://www.acmicpc.net/problem/1931

#include <bits/stdc++.h>

using namespace std;
int d[1000005];
int main(void) {
    int n;
    pair<int, int> s[100005];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i].second >> s[i].first;


    sort(s, s + n);

    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++){
        if(t > s[i].second) continue;
        ans++;
        t = s[i].first;
    }
    cout<<ans;
}