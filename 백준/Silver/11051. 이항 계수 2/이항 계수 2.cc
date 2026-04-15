#include <iostream>
using namespace std;
int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n, k; cin>>n>>k;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 2;
    for(int i =2; i<=n; ++i){
        for(int j=0; j<=k; ++j){
            if(j==0) dp[i][j] = 1;
            if(j==1) dp[i][j] = i;
            if(i == j) dp[i][j] = 1;
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%10007;
        }
    }
    cout<<dp[n][k];
    return 0;
} 
