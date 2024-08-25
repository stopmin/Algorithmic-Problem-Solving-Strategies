//
// Created by 정지민 on 8/26/24.
// https://www.acmicpc.net/problem/11328

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--){
        int ad[26]={0,};
        int bd[26]={0,};

        string a, b;
        cin >> a >> b;

        bool result = true;
        if(a.length() != b.length()) result = false;

        for(int c:a)ad[c-97]++;
        for(int c:b)bd[c-97]++;

        for(int i = 0; i < 26; i++) if (bd[i] != ad[i]) result = false;

        if (result) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}