//
// Created by 정지민 on 8/14/24.
//


#include <iostream>
#include <array>

using namespace std;
int func2(int arr[], int N){
    for (int i = 0 ; i < N; i++){
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == 100) return 1;
        }
    }
    return 0;
}

int main (){
}