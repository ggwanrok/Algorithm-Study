#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> cost;
vector<int> value;
vector<pair<int,int>> pr;

int dp[101];
int res;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    res = 0;
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        cost.push_back(k);
    }
    for(int i=0; i<n; i++){
        int k; cin>>k;
        value.push_back(k);
    }
    
    for(int i=0; i<n; i++){
        for(int c=99; c>=cost[i]; c--){
            //소모된 정신력
            if(c >= 100) break;
            dp[c] = max(dp[c], dp[c-cost[i]] + value[i]);
        }
    }
    for(int cur : dp){
        res = max(res, cur);
    }
    cout<<res<<'\n';
    return 0;
}