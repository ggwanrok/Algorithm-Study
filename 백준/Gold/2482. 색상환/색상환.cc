#include <bits/stdc++.h>
#define MOD 1000000003
using namespace std;

int dp[1001][1001]; // dp[i][j]: i번째 색까지 고려했을 때, j개의 색을 선택하는 경우의 수
int n, m;

void solve() {
    // 초기값 설정
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1; // 0개의 색상을 선택하는 경우: 항상 1가지 (선택 X)
        dp[i][1] = i; // 1개의 색상을 선택하는 경우: i개의 색상 중 하나 선택
    }

    // 점화식 적용
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
        }
    }

    // 첫 번째 색상을 선택한 경우와 선택하지 않은 경우 분리
    int result = (dp[n - 1][m] + dp[n - 3][m - 1]) % MOD;

    cout << result << endl;
}

int main() {
    cin >> n >> m;

    // 예외 처리
    if (m == 0) {
        cout << 1 << endl; // 아무것도 선택하지 않는 경우
    } else if (m > n / 2) {
        cout << 0 << endl; // 선택할 수 없는 경우
    } else {
        solve();
    }

    return 0;
}
