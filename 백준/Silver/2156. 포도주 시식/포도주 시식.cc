#include <iostream>
using namespace std;
int dp[10002];
int al[10002];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>al[i];
    }
    dp[1] = al[1];
    dp[2] = al[1] + al[2];
    for(int i=3; i<=n; ++i){
        dp[i] = dp[i-1];
        if(dp[i]<dp[i-3]+al[i-1]+al[i]) dp[i] = dp[i-3] + al[i-1] + al[i];
        if(dp[i]<dp[i-2]+al[i]) dp[i] = dp[i-2] + al[i];
    }
    cout<<dp[n]<<'\n';
    return 0;
}
