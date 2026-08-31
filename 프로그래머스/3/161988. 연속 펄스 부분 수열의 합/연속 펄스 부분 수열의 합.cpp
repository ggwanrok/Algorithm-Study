#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    //0 이 1일 때, 1이 -1일 때
    //[i][j] 일 때, i까지를 최대 연속 수열이라고 했을 때를 취급.
    vector<vector<long long>> dp(sequence.size(), vector<long long>(2, 0));
    dp[0][0] = sequence[0];
    dp[0][1] = sequence[0]*-1;
    for(int i=1; i<sequence.size(); i++){
        dp[i][0] = sequence[i] + ((0 < dp[i-1][1])? dp[i-1][1] : 0);
        dp[i][1] = sequence[i]*-1 + ((0 < dp[i-1][0])? dp[i-1][0] : 0);
    }
    for(int i=0; i<dp.size(); i++){
        answer = (long long)max(answer, ((dp[i][0] < dp[i][1])?dp[i][1]:dp[i][0]));
    }
    return answer;
}