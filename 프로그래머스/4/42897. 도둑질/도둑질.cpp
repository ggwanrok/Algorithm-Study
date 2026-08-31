#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> money) {
    ios::sync_with_stdio(false);
	cin.tie(0);
    int answer = 0;
    //털었을 때, 안털었을 때
    // vector<vector<int>> dp(money.size(), vector<int>(2, 0));
    int dp[1000001][2];
    //시나리오를 확정지어야 함. 1번집을 털었을 때와 안털었을 때.
    //[i][j] : i까지 도달했을 때, J상태에 도달할 수 있는 최대.
    dp[0][0] = money[0];
    dp[0][1] = 0;
    
    for(int i=1; i<money.size(); i++){
        dp[i][0] = money[i] + dp[i-1][1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    answer = dp[money.size()-1][1];
    
    dp[0][0] = 0;
    dp[0][0] = 0;
    
    for(int i=1; i<money.size(); i++){
        dp[i][0] = money[i] + dp[i-1][1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    
    answer = max(answer, max(dp[money.size()-1][0], dp[money.size()-1][1]));
    
    return answer;
}