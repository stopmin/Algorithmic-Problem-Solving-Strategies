#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> serial;

// 숫자 합을 계산하는 함수
int sum(string x) {
    int cnt = 0;
    for(char c : x) {
        if (isdigit(c)) cnt += c - '0';
    }
    return cnt;
}

// 비교 함수
bool compare(string a, string b) {
    // 1. 길이로 비교
    if (a.length() != b.length())
        return a.length() < b.length();

    // 2. 숫자 합으로 비교
    int sumA = sum(a);
    int sumB = sum(b);
    if (sumA != sumB)
        return sumA < sumB;

    // 3. 사전순으로 비교
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        serial.push_back(s);
    }

    // 정렬
    sort(serial.begin(), serial.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << serial[i] << "\n";
    }
}
