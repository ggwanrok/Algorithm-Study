#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1'000'000'000;

int n;
ll dp[101][10][1 << 10]; // [길이][마지막 숫자][비트마스크]
ll res;

void input();
void func();
void output();


int main() {
    input();
    func();
    output();
    return 0;
}



void func() {
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1; 
    }

    // dp 진행
    for (int i = 2; i <= n; i++) { // 길이
        for (int j = 0; j < 10; j++) { // 마지막 숫자
            for (int mask = 0; mask < (1 << 10); mask++) { // 비트마스크
                if (j > 0) {
                    dp[i][j][mask | (1 << j)] += dp[i - 1][j - 1][mask];
                    dp[i][j][mask | (1 << j)] %= MOD;
                }
                if (j < 9) {
                    dp[i][j][mask | (1 << j)] += dp[i - 1][j + 1][mask];
                    dp[i][j][mask | (1 << j)] %= MOD;
                }
            }
        }
    }

    // 결과 계산
    res = 0;
    for (int j = 0; j < 10; j++) {
        res += dp[n][j][(1 << 10) - 1]; // 0~9 모든 숫자를 사용한 경우
        res %= MOD;
    }
}


void input() {
    cin >> n;
}

void output() {
    cout<<res<<'\n';
}