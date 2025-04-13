#include <bits/stdc++.h>

using namespace std;

int n;

int dp[10][1001]; // (끝자리 숫자, 수의 단위)

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<=9; i++){
        dp[i][1] = 1;
    }
    //idx 번째에 들어가는 숫자가 num이라고 할 때,
    //-1 번째에 있던 숫자 이상이라면 해당 수를 더해줘야 해.
    for(int idx = 2; idx <= n; idx++){
        for(int bef = 0; bef <= 9; bef++){
            for(int cur = bef; cur <= 9; cur++){
                dp[cur][idx] += dp[bef][idx-1];
            }
        }

        for(int i=1; i<=9; i++){
            dp[i][idx] %= 10007;
        }
    }

    int res = 0;
    for(int i=0; i<=9; i++){
        res += dp[i][n];
    }
    cout<<res%10007<<'\n';
    return 0;
}