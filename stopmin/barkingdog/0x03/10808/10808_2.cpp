//
// Created by 정지민 on 8/14/24.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;

    vector<int> count(26);

    for (char c:s){
        count[c-97]++;
    }

    for (auto i:count)
        cout<<i<<" ";

}