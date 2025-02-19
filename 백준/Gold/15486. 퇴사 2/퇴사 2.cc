#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> work; //(소모되는 시간, 비용)
vector<int> dp;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int term, cost;
        cin>>term>>cost;
        work.push_back({term, cost});
    }
    dp.resize(n+1, 0);
}

void func(){
    int res = 0;
    
    int cur_max = 0;
    for(int i=0; i<n; i++){
        int time = work[i].first;
        int cost = work[i].second;
        cur_max = max(cur_max, dp[i]);

        if(i + time <= n && dp[i+time] < cur_max + work[i].second){
            dp[i+time] = cur_max + work[i].second;
        } 
        res = cur_max;    
    }
    res = max(res, dp[n]);
    cout<<res<<'\n';
}

int main(){
    input();
    func();
    return 0;
}