#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 비교 함수 (빈도 기준으로 정렬)
bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second; // 등장 순서로 정렬
    }
    return a.second.first > b.second.first; // 빈도수로 정렬
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> sequence(N);
    map<int, pair<int, int>> freq; // 값 -> <빈도수, 첫 등장 순서>

    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        if (freq.find(sequence[i]) == freq.end()) {
            freq[sequence[i]] = {1, i}; // 첫 등장
        } else {
            freq[sequence[i]].first++; // 빈도수 증가
        }
    }

    vector<pair<int, pair<int, int>>> sorted_freq(freq.begin(), freq.end());
    sort(sorted_freq.begin(), sorted_freq.end(), compare);

    for (auto &p : sorted_freq) {
        for (int i = 0; i < p.second.first; i++) {
            cout << p.first << " ";
        }
    }

    return 0;
}