#include <bits/stdc++.h>

using namespace std;

int ground[1001][1001];
int lenGround[1001][1001];
int res;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int zCnt;
queue<pair<int, int>> oneQ;

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
    if(zCnt > 0){
        cout<<-1<<'\n';
    }
    else{
        cout<<res<<'\n';
    }
}

void func(){
    //while문을 통한 탐색 + bfs 를 정리.
    while(!oneQ.empty()){
        int x = oneQ.front().first;
        int y = oneQ.front().second;
        oneQ.pop();
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(ground[xx][yy] == 0){
                ground[xx][yy] = 1;
                zCnt--;
                lenGround[xx][yy] = lenGround[x][y] + 1;
                if(res < lenGround[xx][yy]) res = lenGround[xx][yy];
                oneQ.push({xx, yy});
            }
        }
    }
}

void input(){
    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t;
            cin>>t;
            ground[i][j] = t;
            if(t == 0){
                zCnt++;
            }
            if(t == 1){
                oneQ.push({i, j});
                lenGround[i][j] = 0;
            }
        }
    }
    
}