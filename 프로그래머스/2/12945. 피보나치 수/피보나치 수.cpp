#include <bits/stdc++.h>

using namespace std;

int dp[100001];


int func(int i){
    if(dp[i] != -1) return dp[i];
    return dp[i] = (func(i-1) + func(i-2))%1234567;
}

int solution(int n) {
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    answer = func(n);
    return answer;
}