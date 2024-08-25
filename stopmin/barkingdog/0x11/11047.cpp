//
// Created by 정지민 on 8/25/24.
//

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n, k;
    int ans = 0;
    cin >> n >> k;

    int a[1000005];
    for (int i = 0; i < n; i++)
        cin >> a[i];


    for (int i = n-1; i >= 0; i--) {
        if (k == 0) break;
        ans += k / a[i];
        k %= a[i];
    }
    cout<<ans;
}