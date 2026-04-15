#include <iostream>
#include <queue>
using namespace std;

/*
입력을 받은 뒤, 방문을 해가면서, 그룹을 찾아나간다.
그룹카운트를 통해서 발전시킬 수 있다.
*/
int res = 1000000;
int n;
int map[101][101];
int vis[101][101];
int group[101][101];
int gCnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y){
    //일단 대륙이야. 방문
    vis[x][y] = 1;
    group[x][y] = gCnt;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx <0 || nx >=n || ny<0 || ny>= n) continue;
            if(map[nx][ny] == 0) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            group[nx][ny] = gCnt;
            q.push({nx, ny});
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] == 0 && map[i][j] != 0){
                gCnt++;
                bfs(i, j);
            }
        }
    }
    //1차 bfs 성공.
    //전체를 탐색하며, 대륙으로부터 시작한 탐색을 실시해야함.
    int dist[101][101];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 0) continue;
            //대륙이면 시작하기.
            /*
            그루핑 값 비교할 변수 하나.
            나아간 거리 생각할 배열 하나
            주변녀석이 같은 대륙이거나 이미 지나간거면 스킵
            */
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = -1;
                }
            }
            int cur_g = group[i][j];
            dist[i][j] = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            while(!q.empty()){
                int xx = q.front().first;
                int yy = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = xx + dx[i];
                    int ny = yy + dy[i];
                    if(nx <0 || nx >=n || ny<0 || ny>= n) continue;
                    if(cur_g == group[nx][ny]) continue;
                    if(dist[nx][ny] != -1) continue;
                    //이젠 다른 대륙이거나 바다임.
                    if(map[nx][ny] == 0){
                        //바다.
                        dist[nx][ny] = dist[xx][yy] +1;
                        q.push({nx, ny});
                    }
                    else{
                        res = res < dist[xx][yy] ? res : dist[xx][yy];

                    }
                }
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}