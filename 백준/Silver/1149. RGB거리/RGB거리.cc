#include <iostream>
using namespace std;
int dp[1001][3];
int col[1001][3];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<3; ++j){
            cin>>col[i][j];            
        }
    }
    dp[0][0]=col[0][0];
    dp[0][1]=col[0][1];
    dp[0][2]=col[0][2];
    //어차피 더해주는 방식을 가져가도 첫줄은 변함없기 때문.
    for(int i=1; i<n; ++i){//시행횟수 -> 세로줄
        for(int j=0; j<3; ++j){//색깔들.. 빨초파
        dp[i][j] = 10000000; // 합의 최소를 구해야하니, 합으로는 나올 수 없는 큰 값을 할당한다.
            for(int k=0; k<3; ++k){//색깔들이긴 한데, 이걸 통해서 겹치는 것을 걸러줄 것임.
                if(j==k) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + col[i][j]);
            }
        }
    }
    cout<<min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    return 0;
}