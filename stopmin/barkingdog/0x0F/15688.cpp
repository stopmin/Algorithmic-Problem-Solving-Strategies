//
// Created by 정지민 on 8/19/24.
//
#include <bits/stdc++.h>

using namespace std;
int N;
int freq[1000001] = {0,};
int freq2[1000001] = {0,};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x >= 0 ) freq[x]++;
        else freq2[abs(x)]++;
    }

    for(int i = 1000001; i > 0; i--)
        for(int j = 0; j < freq2[i]; j++)
            cout << i * -1 << " ";

    for(int i = 0; i < 1000001; i++)
        for(int j = 0; j < freq[i]; j++)
            cout << i << " ";

}
