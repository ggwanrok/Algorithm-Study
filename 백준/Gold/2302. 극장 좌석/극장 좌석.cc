#include <bits/stdc++.h>

using namespace std;

int n, m;
int count_seat[45];
int dp[45][2]; //전꺼 맞는거
int dp_res[45];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    int flag = 0;
    for(int i=0; i<m; i++){
        int k; cin>>k;
        count_seat[k-1-flag]++;
        flag = k;
    }
    if(flag != n){
        //마지막 요소가 고정석이 아니라면, 마지막 덩어리를 또 카운트 해줘야 한다.
        count_seat[n-flag]++;
    }
    //길이 구간에 대한 정립 완료.
    //각 갈이에 대한 가짓수 작업 해준 뒤
    dp[1][0] = 0;
    dp[1][1] = 1;
    for(int i=2; i<=n; i++){
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        dp[i][0] = dp[i-1][1];
    }
    for(int i=1; i<=n; i++){
        dp_res[i] = dp[i][0] + dp[i][1];
    }
    int res = 1;
    for(int i=1; i<=n; i++){
        int loop = count_seat[i];
        while(loop--){
            res *= dp_res[i];
        }
    }
    cout<<res<<'\n';
    return 0;
}