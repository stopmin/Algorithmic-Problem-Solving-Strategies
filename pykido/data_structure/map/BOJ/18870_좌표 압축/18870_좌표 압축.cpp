#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    // 1. 입력 받기
    int N;
    cin >> N; // 입력받은 정수의 개수 N

    vector<int> arr(N); // 원래 배열
    vector<int> arr_sort(N); // 정렬할 배열 (복사본)

    for (int i = 0; i < N; ++i) {
        cin >> arr[i]; // 원래 배열 입력
        arr_sort[i] = arr[i]; // 복사본에 값 복사
    }

    // 2. 배열을 오름차순으로 정렬
    sort(arr_sort.begin(), arr_sort.end()); // 정렬된 배열은 좌표 압축을 위해 사용

    // 3. 해시맵에 정렬된 배열의 index값들을 매핑
    unordered_map<int, int> coord_map; // coord_map 해시맵은 key-value 쌍이 모두 정수값으로 이루어짐
    int idx = 0; // 정렬된 배열의 인덱스 (압축 좌표)

    for (int i = 0; i < N; ++i) {
        // 정렬된 배열 요소 arr_sort[i]가 coord_map에 없다면 coord_map에 추가
        // find 함수는 지정한 키를 검색하고, 키가 존재하지 않는 경우, 해시맵의 끝을 나타내는 반복자(end())를 반환, 참고로 find 함수의 시간복잡도는 O(1)
        if (coord_map.find(arr_sort[i]) == coord_map.end()) {
            coord_map[arr_sort[i]] = idx++; // 압축된 좌표를 저장
        }
    }

    // 4. 결과를 출력
    for (int i = 0; i < N; ++i) {
        // 원래 배열의 값을 압축된 좌표로 변환하여 출력
        cout << coord_map[arr[i]] << " ";
    }

    return 0;
}
