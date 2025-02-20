#include <iostream>

using namespace std;

/*
기본적으로 2일 때 3개를 만들 수 있다.
그리고 수가 늘어가면서, 직전 단계 + 3 + 2 (+ 2개일 때의 경우, + 해당 자리에서의 유니크한 구조의 경우)
*/

int n;
int dp[31];
int main(){
    cin>>n;
    if(n%2 != 0) {
        cout<<0<<'\n';
        return 0;
    }
    n /= 2;
    dp[0] = 0;
    dp[1] = 3;
    dp[2] = 11;
    dp[3] = 41;
    for(int i=4; i<=n; i++){
        dp[i] = 3*dp[i-1] + 3*dp[i-2] - dp[i-3]; + 2;
    }
    cout<<dp[n]<<'\n';
    return 0;
}