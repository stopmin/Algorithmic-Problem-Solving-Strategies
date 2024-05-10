//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입력 받기
    int N;
    cin >> N;
    vector<int> bookPrice;
    for (int i = 0; i < N; i++) {
        int price;
        cin >> price;
        bookPrice.push_back(price);
    }

    // 정렬
    sort(bookPrice.begin(), bookPrice.end());

    // 구현
    int curPrice = bookPrice[0]; // 젤 값 싼 책 값
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (bookPrice[i] >= curPrice*2) {
            curPrice = bookPrice[i];
            cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}

