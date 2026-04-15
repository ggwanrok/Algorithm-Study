#include <bits/stdc++.h>

using namespace std;

int w, j;
int dp[101][101][2][2]; //행, 열, 현재 바라보는 방향(가로/세로), 직전에 꺾었냐?(아니 직진/ㅇㅇ 꺾음)
int main(){
    cin>>w>>j;
    memset(dp, 0, sizeof(dp));
    for(int i=2; i<=w; i++){
        dp[i][1][1][0] = 1; 
    }
    for(int i=2; i<=j; i++){
        dp[1][i][0][0] = 1;
    }
    for(int r=2; r<=w; r++){
        for(int c=2; c<=j; c++){
            dp[r][c][0][0] = dp[r][c-1][0][0] + dp[r][c-1][0][1];
            dp[r][c][0][0] %= 100000;
            dp[r][c][0][1] = dp[r][c-1][1][0];
            dp[r][c][0][1] %= 100000;
            dp[r][c][1][0] = dp[r-1][c][1][0] + dp[r-1][c][1][1];
            dp[r][c][1][0] %= 100000;
            dp[r][c][1][1] = dp[r-1][c][0][0];
            dp[r][c][1][1] %= 100000;
        }
    }
    int result = (dp[w][j][0][0] + dp[w][j][0][1] + dp[w][j][1][0] + dp[w][j][1][1]) % 100000;
    cout << result << '\n';
    return 0;
}
