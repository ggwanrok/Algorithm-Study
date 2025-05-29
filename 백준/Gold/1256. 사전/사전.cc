#include <bits/stdc++.h>
using namespace std;

/*
m, n, k 가 주어질 때 사전순 정렬을 하면 k번쨰 문자열은 뭐냐? 를 말하면 되는 거잖아.
a, z가 적절하게 특정 갯수만큼 섞여있는 구조물의 형태를 떠올려보면 될 것 같은데
2개 2개라면 1개2개 + 2개1개에서 각각 하나씩 앞에 달아주면 되는 구조
*/

int n, m, k;
int dp[101][101]; //{a, z}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=0; i<=100; i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for(int i=1; i<=100; i++){
        for(int j=1; j<=100; j++){
            if(dp[i][j] != 0 ) continue;
            dp[i][j] = min(1000000001, dp[i-1][j] + dp[i][j-1]);
        }
    }

    if(dp[n][m] < k){
        cout<<-1<<'\n';
        return 0;
    }  

    while(n > 0 || m > 0){
        if(n > 0 and dp[n-1][m] >= k){
            cout<<'a';
            n--;
        }
        else{
            cout<<'z';
            if(n>0) k -= dp[n-1][m];
            m--;
        }    
    }
    cout<<'\n';


    return 0;
}