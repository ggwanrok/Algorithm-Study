#include <bits/stdc++.h>

using namespace std;

//어차피 최댓값 하나만 출력하면 되는 구조라 간단.

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> card;
    cin>>n;
    int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    card.push_back(0);
    for(int i=0; i<n; i++){
        int k; cin>>k;
        card.push_back(k);
    }

    //index 만큼의 비용을 동전 취급하는 dp 취급
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            //i : 사용할 카드팩 정보. (예: i = 2 라면, 2개짜리 카드팩의 가격 정보)
            //j : 모금된 금액
            if(j-i < 0){
                dp[i][j] = dp[i-1][j];
                continue;
            }
            dp[i][j] = (dp[i-1][j] > dp[i][j-i] + card[i]) ? dp[i-1][j] : dp[i][j-i] + card[i];
    
        }
    }

    cout<<dp[n][n]<<'\n';

    return 0;
}