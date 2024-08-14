//
// Created by 정지민 on 8/14/24.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string s;
    cin >> s;


    for (char i = 'a'; i <= 'z'; i++) {
        int cnt = 0;
        for (auto c:s)
            if (c==i) cnt++;
        cout<<cnt<<" ";
    }
}