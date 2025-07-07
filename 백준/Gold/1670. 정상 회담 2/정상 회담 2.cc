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
    //곱연산에서 더 타고 들어갈 필요 없음
    if(curr == 0) return 1;
    //해당 수치는 이미 정보가 있음
    if(dp[curr] != -1) return dp[curr];
    ll cur_res = 0;
    for(int i=0; i<curr; i++){
        //curr 만큼의 집단이 서로 악수를 해야한다고 할 때,
        //해당 집단에서의 한명이 다른 누군가와 악수를 하는 경우
        //해당 사람을 기준으로 2개의 그룹으로 분배가 된다.
        //이 때, 각 그룹의 인원수에 따른 존재 경우의 수를 곱연산으로 처리
        cur_res = (cur_res + (fill_dp(i)*fill_dp(curr-1-i))%MOD)%MOD;
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
    //어차피 짝수 인원이니 단순하게 반띵해서 시작.
    cout<<fill_dp(n/2)<<'\n';
    return 0;
}