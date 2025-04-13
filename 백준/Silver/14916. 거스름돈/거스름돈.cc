#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100009];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    fill(dp, dp+100008, 99999);
    // memset(dp, 999999, sizeof(dp));
    dp[2] = 1;
    dp[5] = 1;
    for(int i=1; i<=n; i++){
        if(dp[i] == 99999) continue;
        dp[i+2] = min(dp[i+2], dp[i]+1);
        dp[i+5] = min(dp[i+5], dp[i]+1);
    }
    if(dp[n] == 99999) cout<<-1<<'\n';
    else{
        cout<<dp[n]<<'\n';
    }
    return 0;
}