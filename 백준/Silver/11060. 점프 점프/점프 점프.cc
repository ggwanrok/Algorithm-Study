#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<int> dp;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        arr.push_back(k);
    }
    dp.resize(n, 9999999);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        if(dp[i] == 9999999) continue;
        for(int j=1; j<= arr[i]; j++){
            if(j+i >= n) break;
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }
    if(dp[n-1] == 9999999) cout<<-1<<'\n';
    else cout<<dp[n-1]<<'\n';
    return 0;
}