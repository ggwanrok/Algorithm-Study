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
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==1){
                dp[i] = dp[i] + dp[i-j] * dp[j];
            }
            else if(j == i){
                dp[i] += 2;
            }
            else{
                dp[i] = dp[i] + 2 * dp[i-j];
            }
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}