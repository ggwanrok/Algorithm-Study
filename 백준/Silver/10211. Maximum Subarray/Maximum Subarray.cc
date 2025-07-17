#include <bits/stdc++.h>

using namespace std;

int t;
int n;
vector<int> v;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        dp.clear();
        dp.resize(n);
        for(int i=0; i<n; i++){
            int num; cin>>num;
            v.push_back(num);
        }
        for(int i=0; i<n; i++){
            if(i == 0){
                dp[i] = v[i];
            }
            else{
                dp[i] = max(0, dp[i-1]) + v[i];
            }
        }
        int res = -20000;
        for(int i=0; i<n; i++){
            res = max(res, dp[i]);
        }
        cout<<res<<'\n';
    }

    return 0;
}