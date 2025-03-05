
/*
수행을 시작할 때, +1을 진행해주는 방식.
이건 큐를 이용한 dp를 채택하면 좋을 것 같음.

시작점을 기준으로, 4가지 방향성에 대해서
모든 경우를 다 따져보는데, 넘어갈 때마다 set을 들고 가야하는건가?

루프 존재여부만 단정지을 수 있다면 문제될 내용이 없다.
-> dfs 로 코드를 짜서 수행을 해볼 경우,
-> 이미 탐색된 위치가 존재한다면, 해당 위치는 결국 루프가 생기게 된다는 것을 알 수 있다!!!!
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[51][51];
int dp[51][51];        // dp[x][y]: (x, y)에서 시작했을 때 얻을 수 있는 최대 이동 횟수
bool visited[51][51];  // visited[x][y]: 현재 DFS 경로 상에서 (x, y)를 방문했는지

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 범위 체크
bool is_valid(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < m);
}

// DFS 함수: (x, y)에서 시작했을 때 얻을 수 있는 최대 이동 횟수를 구한다.
// 사이클 발견 시 -1 반환 → main 등에서 처리
int dfs(int x, int y) {
    // 범위 밖이거나 구멍(H)인 경우는 0번 이동으로 종료
    if(!is_valid(x, y) || arr[x][y] == -1) return 0;

    // 이미 이 칸의 최대 이동 횟수를 계산해 둔 경우
    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    // 현재 경로 상에서 이미 방문 중인 칸을 다시 방문하는 경우 → 사이클
    if(visited[x][y]) {
        // 사이클임을 알리기 위해 특정 값을 리턴하고, 
        // 이 값을 보고 -1 출력 후 종료
        return -99999999;  // 큰 음수(또는 상황에 맞게) 리턴
    }

    // 이제 (x,y)를 ‘현재 경로’에 포함시킴
    visited[x][y] = true;

    // arr[x][y]만큼 이동
    int jump = arr[x][y];
    int ret = 0; // (x,y)에서 가능한 최대 이동 횟수

    for(int i=0; i<4; i++){
        int xx = x + dx[i]*jump;
        int yy = y + dy[i]*jump;
        int temp = dfs(xx, yy);
        // 사이클 감지(-99999999) 같은 값이 오면 그대로 전파
        if(temp < 0) {
            return temp;
        }
        ret = max(ret, temp);
    }

    // (x,y) 탐색 종료 후, 경로에서 제외
    visited[x][y] = false;

    // dp[x][y] = 1 + (이동 후 얻을 수 있는 최대 이동 횟수)
    dp[x][y] = 1 + ret;
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            if(s[j] == 'H') {
                arr[i][j] = -1;
            } else {
                arr[i][j] = s[j] - '0';
            }
        }
    }

    memset(dp, -1, sizeof(dp));  // dp 테이블 초기화

    int ans = dfs(0, 0);
    // ans가 0보다 작다면 사이클(-99999999 등)이 전파되었다는 뜻
    if(ans < 0) cout << -1 << '\n';
    else        cout << ans << '\n';

    return 0;
}
