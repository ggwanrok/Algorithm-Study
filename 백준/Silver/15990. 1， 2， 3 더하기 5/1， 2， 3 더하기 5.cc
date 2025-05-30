#include <bits/stdc++.h>
#define ll long long
#define mod 1000000009
using namespace std;

ll dp[100005][4]; //i아라는 값을 만들 때, 마지막에 j를 사용함

void pre_doing(){
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;
    for(int i=2; i<=100000; i++){
        //i를 만드는데 최근 요소를 제거하고 만들어야 함.
        dp[i][3] += (dp[max(0,i-3)][2] + dp[max(0,i-3)][1])%mod;
        dp[i][2] += (dp[max(0,i-2)][1] + dp[max(0,i-2)][3])%mod;
        dp[i][1] += (dp[max(0,i-1)][3] + dp[max(0,i-1)][2])%mod;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre_doing();
    int tc; cin>>tc;
    while(tc--){
        int num; cin>>num;

        cout<<(dp[num][1]+dp[num][2]+dp[num][3])%mod<<'\n';
    }

    return 0;
}