#include <bits/stdc++.h>

using namespace std;

long long dp[120];

int main(){
    int n;
    dp[1] = dp[2] = dp[3] = 1;
    for(int i=4; i<=116; i++){
        dp[i] = dp[i-1] + dp[i-3];
    }
    cin>>n;
    cout<<dp[n]<<'\n';
    return 0;
}