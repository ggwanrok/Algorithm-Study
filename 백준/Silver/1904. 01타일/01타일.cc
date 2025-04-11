#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    dp[1] = 1; // 1
    dp[2] = 1; // 00
    for(int i=2; i<=n; i++){
        for(int c=1; c<=2; c++){
            int cur = i-c;
            if(cur >= 0){
                dp[i] += dp[cur];
                dp[i] %= 15746;
            }
        }
    }
    cout<<dp[n]%15746<<'\n';
    return 0;
}