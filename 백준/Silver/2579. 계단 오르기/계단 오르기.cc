#include <iostream>
using namespace std;
int st[333];
int dp[333];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    st[0] = 0;
    dp[0] = 0;
    int cnt = 0;
    int n; cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>st[i];//계단마다 부여된 점수
    }
    dp[1] = st[1];
    dp[2] = dp[1] + st[2];
    dp[3] = max(st[1], st[2]) + st[3];
    for(int i=4; i<=n; ++i){
        dp[i] = max(dp[i-3]+ st[i-1], dp[i-2]) + st[i];
    }
    cout<<dp[n];
    return 0;
}