//start : 02:24
#include <bits/stdc++.h>

using namespace std;

int n, d;
int dp[10001];
vector<pair<int, pair<int, int>>> v;

int main(){
    cin>>n>>d;
    for(int i=0; i<=d; i++){
        dp[i] = i;
    }
    for(int i=0; i<n; i++){
        int start, end, cost;
        cin>>start>>end>>cost;
        v.push_back({end, {start, cost}});
    }
    sort(v.begin(), v.end());
    for(auto iter : v){
        int start, end, cost;
        end = iter.first;
        start = iter.second.first;
        cost = iter.second.second;
        //갱신이 필요하다면
        if(dp[end] > dp[start] + cost){
            int cur_cost = dp[start] + cost;
            for(int i=end; i<=d; i++){
                dp[i] = min(dp[i], cur_cost + i-end);
            }
        }
    }
    cout<<dp[d]<<'\n';
    return 0;
}