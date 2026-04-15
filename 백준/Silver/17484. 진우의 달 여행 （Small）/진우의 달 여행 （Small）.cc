#include <bits/stdc++.h>

using namespace std;

int n, m;
int channel_cost[10][10];

//[i][j][k] 에 대해서, ij에 도달할 때 k의 움직임을 취했을 때의 최소 도달 값.
//k: 0-좌하강 | 1-직하강 | 2-우하강
int dp[10][10][3]; 

bool is_in(int a, int b){
    if(a < 1 || a > n || b < 1 || b > m) return false;
    return true;
}

int set_cost(int i, int j, int c){
    int answer = 1000000;
    if(c == 0){
        if(is_in(i-1, j+1)){
            answer = min(dp[i-1][j+1][1], dp[i-1][j+1][2]);
        }
    }

    if(c == 1){
        if(is_in(i-1, j)){
            answer = min(dp[i-1][j][0], dp[i-1][j][2]);
        }
    }

    if(c == 2){
        if(is_in(i-1, j-1)){
            answer = min(dp[i-1][j-1][0], dp[i-1][j-1][1]);
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>channel_cost[i][j];
        }
    }

    memset(dp, 100000, sizeof(dp));

    
    //dp의 초깃값 설정
    for(int i=1; i<=m; i++){
        dp[1][i][0] = channel_cost[1][i];
        dp[1][i][1] = channel_cost[1][i];
        dp[1][i][2] = channel_cost[1][i];
    }

    //filling dp-array
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j][0] = channel_cost[i][j] + set_cost(i, j, 0);
            dp[i][j][1] = channel_cost[i][j] + set_cost(i, j, 1);
            dp[i][j][2] = channel_cost[i][j] + set_cost(i, j, 2);
        }
    }

    //find answer
    int res = 1000000;
    for(int i=1; i<=m; i++){
        for(int j=0; j<3; j++){
            res = min(res, dp[n][i][j]);
        }
    }

    cout<<res<<'\n';

    return 0; 
}