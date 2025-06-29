#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<double> v;
    for(int i=0; i<n; i++){
        double k; cin>>k;
        v.push_back(k);
    }
    vector<double> dp(n+1, 0);
    dp[0] = v[0];
    for(int i=1; i<n; i++){
        dp[i] = max(v[i], dp[i-1] * v[i]);
    }
    double maxi = -1;
    for(int i=0; i<n; i++){
        maxi = max(maxi, dp[i]);
    }
    cout<<fixed, cout.precision(3);
    cout<<maxi<<'\n';
    return 0;
}