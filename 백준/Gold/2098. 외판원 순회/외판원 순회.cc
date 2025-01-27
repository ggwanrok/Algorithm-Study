#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
int arr[17][17];

int dp[1<<16][17];

void input();
void output();
int func(int, int);

int main(){
    input();
    output();
    return 0;
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int k; cin>>k;
            arr[i][j] = k;
        }
    }
    for(int i=0; i<(1 << n); i++){
        fill(dp[i], dp[i]+n, -1);
    }
}


int func(int visited, int current) {
    // 모든 도시를 방문한 경우
    if (visited == (1 << n) - 1) {
        return arr[current][0] ? arr[current][0] : INF; // 시작점으로 돌아가는 비용
    }

    // 메모이제이션
    if (dp[visited][current] != -1) {
        return dp[visited][current];
    }

    dp[visited][current] = INF; // 초기값 설정

    // 다음 도시 탐색
    for (int next = 0; next < n; next++) {
        if (visited & (1 << next)) continue; // 이미 방문한 도시라면 건너뜀
        if (arr[current][next] == 0) continue; // 경로가 없는 경우 건너뜀

        // 현재 도시에서 next 도시로 이동
        dp[visited][current] = min(
            dp[visited][current],
            arr[current][next] + func(visited | (1 << next), next)
        );
    }

    return dp[visited][current];
}

void output(){
    cout<<func(1, 0)<<'\n';
}