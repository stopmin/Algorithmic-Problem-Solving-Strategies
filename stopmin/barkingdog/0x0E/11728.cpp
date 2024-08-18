//
// Created by 정지민 on 8/18/24.
//

#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr1[1000001];
int arr2[1000001];
int ans[2000002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr1[i];

    for (int i = 0; i < M; i++)
        cin >> arr2[i];

    int idx = 0;
    int ptr1 = 0;
    int ptr2 = 0;

    while (N != ptr1 && M != ptr2) {
        if (arr1[ptr1] < arr2[ptr2]) {
            ans[idx++] = arr1[ptr1++];
        } else {
            ans[idx++] = arr2[ptr2++];
        }
    }

    while(N>ptr1) ans[idx++] = arr1[ptr1++];
    while(M>ptr2) ans[idx++] = arr2[ptr2++];


    for (int i = 0; i < N + M; i++)
        cout << ans[i] << " ";
}