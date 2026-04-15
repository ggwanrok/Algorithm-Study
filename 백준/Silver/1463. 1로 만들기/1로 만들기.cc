#include <iostream>
using namespace std;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    dp[1] =0;
    for(int i=2; i<=n; ++i){
        dp[i] = dp[i-1] +1;
        if(i%2==0 && dp[i]>dp[i/2]+1){
            dp[i] = dp[i/2]+1;
        }
        if(i%3==0 && dp[i]>dp[i/3]+1){
            dp[i] = dp[i/3]+1;
        }
    }
    cout<<dp[n];
    return 0;
}