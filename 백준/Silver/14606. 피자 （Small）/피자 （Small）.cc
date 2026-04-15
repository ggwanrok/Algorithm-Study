#include <bits/stdc++.h>

using namespace std;

int dp[11];

int find_fun(int a){
    if(dp[a] != -1) return dp[a];
    int max_value = 0;
    for(int i=1; i<a; i++){
        max_value = max(max_value, i * (a-i) + find_fun(i) + find_fun(a-i));
    }
    return dp[a] = max_value;
}

int main(){
    memset(dp, -1, sizeof(dp));
    dp[2] = 1;
    dp[1] = 0;
    int n; cin>>n;
    cout<<find_fun(n)<<'\n';
    return 0;
}