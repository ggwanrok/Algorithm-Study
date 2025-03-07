#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;  // 예외 처리: N이 number와 같으면 1 반환
    
    vector<unordered_set<int>> dp(9); // dp[i]: N을 i번 사용하여 만들 수 있는 수들
    
    // 1. 초기값 설정 (N, NN, NNN, ...)
    int num = 0;
    for (int i = 1; i <= 8; i++) {
        num = num * 10 + N;
        dp[i].insert(num);
    }
    
    // 2. 동적 프로그래밍으로 가능한 숫자 계산
    for (int i = 1; i <= 8; i++) {  // i: 사용한 횟수
        for (int j = 1; j < i; j++) {  // j: 나누는 지점
            int k = i - j; // 남은 횟수
            
            for (int a : dp[j]) {
                for (int b : dp[k]) {
                    dp[i].insert(a + b);
                    if(a-b > 0) dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        
        // 원하는 값이 나오면 즉시 반환
        if (dp[i].count(number)) return i;
    }
    
    return -1; // 8번을 초과하면 만들 수 없음
}
