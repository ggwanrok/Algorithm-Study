#include <iostream>
using namespace std;
int dp[1001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    dp[1] = 1;
    dp[2] = 3;
    int n; cin>>n;
    for(int i=3; i<=n; ++i){
        dp[i]=((2*dp[i-2]+dp[i-1])%10007);
    }
    cout<<dp[n];
    return 0;
}