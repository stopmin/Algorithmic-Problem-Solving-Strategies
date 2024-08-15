#include <bits/stdc++.h>

using namespace std;


void func(int n, int a, int b) {
    if (n == 1) {
        printf("%d %d\n", a, b);
        return;
    }

    func(n - 1, a, 6 - a - b);
    printf("%d %d\n", a, b);
    func(n - 1, 6 - a - b, b);
}


int main(void) {
    int N;
    cin >> N;
    string str;

    str = to_string(pow(2, N));
    str = str.substr(0, str.find('.'));
    str.back()--;
    cout << str;

    if (N <= 20) {
        cout << "\n";
        func(N, 1, 3);
    }
    return 0;
}
