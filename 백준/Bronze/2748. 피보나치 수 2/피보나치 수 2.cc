#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    long long dp[91] = {0, };
    dp[0] = 0; dp[1] = 1;
    int n; cin>>n;
    for(int i=2; i<=n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n];
    return 0;
}
