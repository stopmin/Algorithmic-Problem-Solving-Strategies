//
// Created by 정지민 on 8/14/24.
//

#include <iostream>
using namespace std;

int calc_sum(int x){
    return x * (1 + x)/2;
}

int solution(int x){
    int multiple_3, multiple_5, multiple_15;
    multiple_3 = x / 3;
    multiple_5 = x / 5;
    multiple_15 = x / 15;
    return  calc_sum(multiple_3) * 3 + calc_sum(multiple_5) * 5 - calc_sum(multiple_15) * 15;;
}

int main() {
    int N;
    cin >> N;

    int answer = solution(N);
    cout<<answer;
}

