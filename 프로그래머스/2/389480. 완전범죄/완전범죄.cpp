#include <string>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<int> dp(m, INF);
    dp[0] = 0;

    for (auto cur : info) {
        int da = cur[0];
        int db = cur[1];

        vector<int> next(m, INF);
        /*각 cur에 대해서,
        b가 i 만큼 훔쳤을 때, 가지고 있는 a가 훔친 정보의 최솟값이 dp에 저장되어 있다.
        직전까지 고려한 dp를 기반으로 현시점 훔침행동을 통해서 업데이트 할 수 있는 정보를 next에 저장
        반드시 step이 진행되어야 하기에 dp를 기반으로 처리
        이후 dp에 덮어쓰기
        */
        for (int i = 0; i < m; i++) {
            if(dp[i] == INF) continue;
            if(dp[i] + da < n){
                next[i] = min(next[i], dp[i] + da);
            }
            if(i + db < m){
                next[i+db] = min(next[i+db], dp[i]);
            }
        }
        dp = move(next);
    }

    int answer = INF;
    for (int i = 0; i < m; i++) {
        answer = min(answer, dp[i]);
    }

    return answer == INF ? -1 : answer;
}