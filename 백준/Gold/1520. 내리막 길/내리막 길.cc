#include <iostream>
using namespace std;

/*
전형적인 2차원 배열 dp 문제 같다.
항상 arr 내용물이 높은 곳에서 낮은 곳으로 이동하기 때문에, 구조적으로 사이클이 생길 수 없다.
탐색방식을 bfs 형식으로 가야할 것 같은데?
-> bfs의 경우에는 큐에 
*/

int n, m;
int arr[501][501];
int dp[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        if(arr[xx][yy] < arr[x][y]){
            dp[x][y] += dfs(xx, yy);
        }
    }
    return dp[x][y];
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout<<dfs(0, 0)<<'\n';
    
    return 0;
}