#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MOD = 1e9;
long long dp[201][201]; // dp[i][j] : i개의 수로 j를 만드는 경우의 수

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    for (int i = 0; i <= n; i++) dp[1][i] = 1; // 1개로 i를 만드는 경우는 무조건 1

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
            }
        }
    }

    cout << dp[k][n] << '\n';
    return 0;
}
