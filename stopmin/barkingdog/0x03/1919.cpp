//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/1919

#include <bits/stdc++.h>

using namespace std;
#define N 26

int main(void) {
    vector<int> v1(N);
    vector<int> v2(N);
    string str1, str2;
    int res = 0;

    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++)
        v1[str1.at(i) - 'a']++;

    for (int i = 0; i < str2.size(); i++)
        v2[str2.at(i) - 'a']++;


    for (int i = 0; i < N; i++)
        res += abs(v1[i] - v2[i]);


    cout << res;
}
