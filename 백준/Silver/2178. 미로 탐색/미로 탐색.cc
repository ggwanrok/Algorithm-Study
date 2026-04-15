#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[101][101];
int dist[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input();
void func();
void output();

int main(void){
    input();
    func();
    output();
    return 0;
}

void output(){
    cout<<dist[n][m]<<'\n';
}

void func(){
    //arr[1][1]로부터 arr[n][m] 까지 이동하는 거리를 탐색해야함.
    //dist배열이 -1로 초기화되어 있다.
    //bfs를 통해서 이미 지나간 경로가 아니라면, 업데이트하여 문제를 풀이하자.
    dist[1][1] = 1;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 1 || yy < 1 || xx > n || yy > m) continue;
            if(arr[xx][yy] == 0) continue;
            if(dist[xx][yy] != -1) continue;
            q.push({xx, yy});
            dist[xx][yy] = dist[x][y] + 1;
        }
    }
}

void input(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        string input_line;
        cin>>input_line;
        for(int j=0; j<m; j++){
             arr[i][j+1] = input_line[j] - '0';
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dist[i][j] = -1;
        }
    }
}