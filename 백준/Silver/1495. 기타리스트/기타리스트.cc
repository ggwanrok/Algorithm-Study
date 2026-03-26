#include <bits/stdc++.h>

using namespace std;

int n, s, m; //input, start_value, floor_value
vector<int> dp;

int main(){
    cin>>n>>s>>m;
    dp.resize(m+1, -1);
    vector<int> input_vec;
    while(n--){
        int k; cin>>k;
        input_vec.push_back(k);
    }
    dp[s] = 1;
    for(int i=0; i<input_vec.size(); i++){
        vector<int> tmp(m+1, -1);
        for(int j=0; j<=m; j++){
            if(dp[j] == -1) continue;
            if(j-input_vec[i] >= 0){
                tmp[j-input_vec[i]] = 1;
            }
            if(j+input_vec[i] <= m){
                tmp[j+input_vec[i]] = 1;
            }
        }
        dp = std::move(tmp);
    }
    int res = -1;
    for(int i=m; i>=0; i--){
        if(dp[i] != -1) {
            res = i;
            break;
        }
    }
    cout<<res<<'\n';
    return 0;
}