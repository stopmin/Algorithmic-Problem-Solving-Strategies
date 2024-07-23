#include <iostream>
#include <algorithm>

using namespace std;

int N; // 탕후루에 꽂혀 있는 과일의 개수
int nums[10] = {}; // 과일 종류는 1~9 뿐이다.
int arr[200001]; // 탕후루에 꽂혀 있는 과일들

// 2종류의 숫자로 이루어진 가장 긴 탕후루 길이 찾는 문제 !!!

int twoPointer(int left, int right,int cnt, int kind, int maxVal) {
    // 만약 오른쪽 포인터가 끝을 도달하면 현재 탕후루의 최대 길이 반환
    if (right >= N) {
        return maxVal;
    }

    // 오른쪽 포인터가 위치한 곳에 있는 과일이 새롭게 추가되는 과일의 종류라면 종류 + 1
    if (nums[arr[right]] == 0) {
        kind ++;
    }

    // 탕후루 길이 + 1, 종류가 arr[right]인 과일 + 1
    cnt += 1;
    nums[arr[right]] += 1;

    // 과일의 종류가 2개를 넘는다면 왼쪽 포인터를 이동시켜본다.
    if (kind > 2) {
        // 왼쪽 포인터가 위치한 과일 한 개 빼기
        nums[arr[left]] -= 1;

        // 만약 왼쪽 포인터가 위치한 과일이 영역 내에 더 이상 존재하지 않는다면 종류 한 개 줄어든 것
        if (nums[arr[left]] == 0) {
            kind--;
        }

        // 탕후루 길이 1개 줄이고, 왼쪽 포인터 옮기기
        cnt--;
        left++;
    }

    // 최대값 갱신
    maxVal = max(maxVal, cnt);

    // left pointer는 그대로 두고, right 포인터만 배열의 끝으로 계속해서 이동
    return twoPointer(left, right + 1, cnt, kind, maxVal);
}

int main() {
    // 1. 입력 받기
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 2. 구현하기
    cout << twoPointer(0,0,0,0,0);

    return 0;
}