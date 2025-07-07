/*
알약의 갯수가 주어진다.
해당 알약을 기준으로, 
하나짜리/반짜리
의 갯수를 기반으로 하여,
첫날에 뭘 사용할 것인지를 판가름하여,
재귀적으로 업데이트하면 될 것 같은데
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tc;
ll dp[31][61];

ll fill_dp(int full, int half){
    if(dp[full][half] != -1) return dp[full][half];
    ll cur_value = 0;
    if(full > 0){
        cur_value += fill_dp(full-1, half+1);
    }
    if(half > 0){
        cur_value += fill_dp(full, half-1);
    }
    return dp[full][half] = cur_value;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 1;
    dp[0][1] = 1;
    while(true){
        cin>>tc;
        if(tc == 0) break;
        cout<<fill_dp(tc, 0)<<'\n';
    }
    return 0;
}