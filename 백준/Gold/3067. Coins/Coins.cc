#include <bits/stdc++.h>

using namespace std;

vector<int> coins;
vector<int> dp;

int main(){
    int tc; cin>>tc;
    while(tc--){
        int n;
        int target;
        coins.clear();
        dp.clear();
        cin>>n;
        dp.resize(n+20000, 0);
        for(int i=0; i<n; i++){
            int val; cin>>val;
            coins.push_back(val);
        }
        cin>>target;
        dp[0] = 1;
        for(int val : coins){
            for(int i=0; i<=target; i++){
                dp[i+val] += dp[i];
            }
        }
        cout<<dp[target]<<'\n';
    }
    return 0;
}