#include <bits/stdc++.h>
using namespace std;

int dp[501][501];  // dp[i][j]: i~j까지 합치는 최소 비용
int cost[501];     // 파일 크기 저장
int sum[501];      // 누적합 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc; // 테스트 케이스 개수
    
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];  // 누적합 계산
        }

        // DP 초기화
        memset(dp, 0, sizeof(dp));  // 초기화 (모든 값을 0으로)

        // 간격(len)을 2부터 n까지 증가시키며 계산
        // 반복문을 이런식으로 구성하면, 바텀업 형식으로 보장된 결과가 도출됨.
        for (int len = 2; len <= n; len++) { 
            for (int i = 1; i + len - 1 <= n; i++) { 
                int j = i + len - 1;  
                dp[i][j] = INT_MAX; // 최소값을 찾기 위해 초기화

                // i~j를 k 기준으로 두 부분으로 나누어 탐색
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][n] << "\n"; // 최종 결과 출력
    }
    return 0;
}
