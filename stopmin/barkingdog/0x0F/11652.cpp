#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_map<ll, int> freq;
    ll max_card = 0;
    int max_freq = 0;

    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        freq[x]++;
        if (freq[x] > max_freq || (freq[x] == max_freq && x < max_card)) {
            max_freq = freq[x];
            max_card = x;
        }
    }

    cout << max_card;
}
