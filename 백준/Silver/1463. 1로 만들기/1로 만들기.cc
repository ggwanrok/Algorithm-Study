#include <iostream>
using namespace std;
int dp[1000001];
int solve(int x){
    if(x==1) return 0;
    if(dp[x] != 0) return dp[x];
    dp[x] = solve(x-1);
    if(x%2==0){
        dp[x] = min(dp[x], solve(x/2));
    }
    if(x%3==0){
        dp[x] = min(dp[x], solve(x/3));
    }
    dp[x]++;
    return dp[x];
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    cout<<solve(n);
    return 0;
}