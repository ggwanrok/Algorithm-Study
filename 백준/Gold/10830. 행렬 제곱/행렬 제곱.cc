#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long>> Matrix;
const int MOD = 1000;

// 행렬 곱셈 함수
Matrix matrix_mult(const Matrix &, const Matrix &, int);
// 행렬 거듭제곱 함수
Matrix matrix_pow(Matrix, long long, int);

int main() {
    int n;
    long long b;
    cin >> n >> b;
    
    Matrix matrix(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    Matrix result = matrix_pow(matrix, b, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


Matrix matrix_mult(const Matrix& A, const Matrix& B, int n) {
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += (A[i][k] * B[k][j]) % MOD;
            }
            result[i][j] %= MOD;
        }
    }
    return result;
}


Matrix matrix_pow(Matrix A, long long B, int n) {
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1; // 단위 행렬로 초기화
    }
    while (B > 0) {
        if (B % 2 == 1) {
            result = matrix_mult(result, A, n);
        }
        A = matrix_mult(A, A, n);
        B /= 2;
    }
    return result;
}
