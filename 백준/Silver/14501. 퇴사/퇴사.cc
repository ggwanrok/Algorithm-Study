#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> work; //(소모되는 시간, 비용)
vector<int> dp;
void input(){
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
    for(int i=0; i<n; i++){
        int time = work[i].first;
        int cost = work[i].second;
        int cur_max = 0;
        for(int j=0; j<=i; j++){
            cur_max = max(cur_max , dp[j]);
        }
        if(i + time <= n && dp[i+time] < cur_max + work[i].second){
            dp[i+time] = cur_max + work[i].second;
            res = max(res, dp[i+time]);
        } 
    }
    cout<<res<<'\n';
}

int main(){
    input();
    func();
    return 0;
}