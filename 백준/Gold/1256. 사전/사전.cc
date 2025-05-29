#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[101][101]; // dp[a][z] = a개, z개로 만들 수 있는 문자열 개수

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    // 사전 만들기: 가능한 개수 미리 계산
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int i=0; i<=m; i++) dp[0][i] = 1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = min(1000000001LL, dp[i-1][j] + dp[i][j-1]);
        }
    }

    if(dp[n][m] < k){
        cout << -1 << '\n';
        return 0;
    }

    while(n > 0 || m > 0){
        if(n == 0){
            cout << 'z';
            m--;
        } else if(m == 0){
            cout << 'a';
            n--;
        } else {
            ll left = dp[n-1][m]; // 'a'를 먼저 넣을 경우의 경우 수
            if(k <= left){
                cout << 'a';
                n--;
            } else {
                cout << 'z';
                k -= left;
                m--;
            }
        }
    }
    cout << '\n';
    return 0;
}