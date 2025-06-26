//start : 01:00
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // pre();
    int n; cin>>n;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=1; i<=n; i++){
        int a, b;
        cin>>a>>b;
        for(int i=3; i<=a; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % b;
        }
        cout<<"Case #"<<i<<": "<<dp[a]%b<<'\n';
    }

    return 0;
}