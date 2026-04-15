#include <iostream>
using namespace std;
int dp[101][100001];
int val[101];
int wei[100001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n, k; cin>>n>>k;
    for(int i=1; i<=n; ++i){
        cin>>wei[i]>>val[i];
    }
    for(int i=1; i<=n; ++i){
        for(int w=1;w<wei[i];++w){
            dp[i][w] = dp[i-1][w];
        }
        for(int w=wei[i]; w<=k; ++w){
            dp[i][w] = max(dp[i-1][w], dp[i-1][w-wei[i]]+val[i]);
        }
    }
    cout<<dp[n][k];
    return 0;
} 
