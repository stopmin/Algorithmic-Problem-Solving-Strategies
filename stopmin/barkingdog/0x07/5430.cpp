#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string op, arr;
        int n, number;
        cin >> op >> n >> arr;

        deque<int> dq;
        stringstream ss(arr.substr(1, arr.size() - 2));  // 괄호 제거 후 숫자 파싱
        while (ss >> number) {
            dq.push_back(number);
            if (ss.peek() == ',') ss.ignore();
        }

        bool error = false, reversed = false;
        for (char c : op) {
            if (c == 'R') {
                reversed = !reversed;  // 뒤집힘 상태 토글
            } else if (c == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (reversed) dq.pop_back();
                else dq.pop_front();
            }
        }

        if (error) {
            cout << "error\n";
        } else {
            cout << '[';
            if (reversed) {
                for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                    if (it != dq.rbegin()) cout << ",";
                    cout << *it;
                }
            } else {
                for (auto it = dq.begin(); it != dq.end(); ++it) {
                    if (it != dq.begin()) cout << ",";
                    cout << *it;
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
