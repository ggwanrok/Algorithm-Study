#include <bits/stdc++.h>

using namespace std;

/*
0,0 에서 n-1,n-1로 도달하는 경로의 갯수.
결국 올 수 있는 모든 경우를 따져야 함.
시작점으로부터 도달할 수 있는 경로에 대해서 재귀를 하는 것 말고는 뭐
*/
long long dx[2] = {0, 1};
long long dy[2] = {1, 0};
long long res;
long long n;
long long arr[101][101];
long long dp[101][101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    res = 0;
    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            long long k; cin>>k;
            arr[i][j] = k;
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            if(arr[i][j] == 0 ) continue;
            for(long long l=0; l<2; l++){
                long long ii = i + dx[l]*arr[i][j];
                long long jj = j + dy[l]*arr[i][j];
                if(ii >= n || jj >= n) continue;
                
                dp[ii][jj] += dp[i][j];
            }
        }
    }
    
    cout<<dp[n-1][n-1]<<'\n';

    return 0;
}