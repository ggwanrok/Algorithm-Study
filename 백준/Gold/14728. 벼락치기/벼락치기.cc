#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return (double)a.second/a.first > (double)b.second/b.first;
}

int n, t;

int main(){
    cin>>n; cin>>t;
    vector<pair<int, int>> test;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        test.push_back({a, b});
    }
    sort(test.begin(), test.end(), compare);

    vector<int> dp(t+1, 0);
    for(int i=0; i<test.size(); i++){
        int wei = test[i].first;
        int cost = test[i].second;

        for(int w = t; w >= wei; w--){
            dp[w] = max(dp[w-wei] + cost, dp[w]);
        }
    }
    cout<<dp[t]<<'\n';

    return 0;
}