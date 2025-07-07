/*
start : 06:00
결국, 주어지는 녀석들은 소규모 집단으로의 분할이 가능하다.
결국 끝까지 오면 return 1
스킵해서 뭔가를 한다면, 해당 녀석만큼 + 처리를 진행해준다.
*/

#include <bits/stdc++.h>
#define MOD 987654321
#define ll long long
using namespace std;

int n;
ll dp[10001];

ll fill_dp(int curr){
    if(curr == 0) return 1;
    if(dp[curr] != -1) return dp[curr];
    ll cur_res = 0;
    for(int i=0; i<curr; i++){
        cur_res = (cur_res + (fill_dp(i)*fill_dp(curr-i-1))%MOD)%MOD;
    }
    return dp[curr] = cur_res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    cin>>n;
    cout<<fill_dp(n/2)<<'\n';
    return 0;
}