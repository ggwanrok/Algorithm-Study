#include <bits/stdc++.h>
using namespace std;

int dp[501][501]; 
int cost[501]; 
int sum[501]; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }

        // DP 초기화
        memset(dp, 0, sizeof(dp));

        // 간격 2부터 n까지 구간을 설정
        for (int len = 2; len <= n; len++) { 
            for (int i = 1; i + len - 1 <= n; i++) { 
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                // i~j를 k 기준으로 두 부분으로 나누기
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
    return 0;
}
