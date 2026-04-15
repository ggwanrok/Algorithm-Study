#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
1부터 시작해서, an = 1 + 2an_1 개의 패티를 가진다.
1부터 시작해서, an = 3 + 2an_1 개의 빵크기를 가진다.

n을 입력받아서, 해당 레발까지 진행했을 떄, 패티 수, 빵 수를 체크한다.
빵 수를 체크해가며, 빵의 레벨을 포괄적 포함하지 못한다면, 줄여가는 코드를 짜보자.
*/

ll dp1[51]; //meat
ll dp2[51]; //bread

ll n, x;

ll div_buger(int buger_lev, ll x){ //x : 몇번째 부분까지 먹을거냐
    if(x == 1){
        if(buger_lev == 0) return 1;
        else return 0;
    }
    else if(x == dp2[buger_lev]){
        return dp1[buger_lev];
    }
    else if(x < (dp2[buger_lev] + 1)/2){
        return div_buger(buger_lev-1, x-1);
    }
    else if(x == (dp2[buger_lev] + 1)/2){
        //lev-1까지 먹고 패티 한장 더 먹는다.
        return dp1[buger_lev-1] + 1;
    }
    else{
        return dp1[buger_lev-1] + 1 + div_buger(buger_lev-1, x-dp2[buger_lev-1]-1-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dp1[0] = 1;
    dp2[0] = 1;
    cin>>n>>x;
    for(int i=1; i<=n; i++){
        dp1[i] = 1 + 2 * dp1[i-1];
        dp2[i] = 3 + 2 * dp2[i-1];
    }

    cout<<div_buger(n, x)<<'\n';

    return 0;
}