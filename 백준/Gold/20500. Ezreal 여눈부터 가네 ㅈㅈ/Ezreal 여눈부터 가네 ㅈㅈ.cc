#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n;
int dp[1516][3];

int main(){
    cin>>n;
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i=2; i<=n; i++){
        dp[i][0] = (dp[i-1][1] + dp[i-1][2])%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%mod;
    }
    cout<<dp[n-1][1]<<'\n';
    return 0;
}