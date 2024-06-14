//
//

#include <iostream>
#include <vector>

using namespace std;

// 1. 1 ~ n 수열의 합을 분할 정복을 이용해 빠르게 구하는 방법
// fastSum(n) = 1 + 2 + ... + n
//           = (1 + 2 + ... + n/2) + {(1 + n/2) + (2 + n/2) + ... + (n/2 + n/2)}
//           = 2 * fastSum(n/2) + (n/2 * n/2) (짝수일 때)
int fastSum(int n) {
    // 기저 사례
    if (n == 1) return 1;
    // 짝수 일 때
    if (n % 2 == 0) {
        return 2 * fastSum(n/2) + (n/2) * (n/2);
    } else {
        // 홀수 일 때 짝수화
        return fastSum(n - 1) + n;
    }
}

// 2. 행렬의 거듭제곱을 구하는 분항 정복 알고리즘
// 기본적으로 n x n 크기의 행렬 A의 행렬 곱셉인 A**2에는 O(n**3)의 시간이 소요된다.
// A**m의 경우 O(n**3 x (m-1))의 시간이 걸리게 된다!
// m이 짝수인 경우 A**m = A**(m/2) x A**(m/2)로 분할하여 생각할 수 있다.
// (1) 정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정하자.
class SquareMatrix {
public:
    int n;
    vector<vector<int> > mat;

    // 생성자: 크기 n과 초기 값 val로 행렬을 초기화
    SquareMatrix(int n, int val = 0) : n(n), mat(n, std::vector<int>(n, val)) {}

    // 행렬 초기화를 위한 추가 생성자
    SquareMatrix(const std::vector<std::vector<int> >& values) {
        n = values.size();
        mat = values;
    }

    // 행렬 곱셈 연산자 오버로드
    SquareMatrix operator*(const SquareMatrix& other) const {
        SquareMatrix result(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // 행렬의 크기를 반환하는 함수
    int size() const {
        return n;
    }

    // 행렬을 출력하는 함수
    void print() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// (2) n*n 크기의 항등 행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n) {
    SquareMatrix I(n);
    for (int i = 0; i < n; ++i) {
        I.mat[i][i] = 1;
    }
    return I;
}

// (3) A**m 반환
SquareMatrix pow(const SquareMatrix& A, int m) {
    // 기저 사례 : A**0 = I
    if (m == 0) return identity(A.size());
    if(m % 2 > 0) return pow(A, m - 1) * A;
    SquareMatrix half = pow(A, m / 2);
    // A**m = A**(m/2) x A**(m/2)
    return half * half;
}


int main() {
    // 1.
    cout << fastSum(10) << '\n';
    cout << fastSum(11) << '\n';

    // 2.
    int n = 3;
    vector<vector<int> > values(n, vector<int>(n));
    values[0][0] = 1;
    values[0][1] = 2;
    values[0][2] = 3;
    values[1][0] = 4;
    values[1][1] = 5;
    values[1][2] = 6;
    values[2][0] = 7;
    values[2][1] = 8;
    values[2][2] = 9;

    SquareMatrix A(values);

    std::cout << "Matrix A:" << std::endl;
    A.print();

    int m = 2;
    SquareMatrix result = pow(A, m);

    std::cout << "Matrix A^" << m << ":" << std::endl;
    result.print();

    return 0;
}