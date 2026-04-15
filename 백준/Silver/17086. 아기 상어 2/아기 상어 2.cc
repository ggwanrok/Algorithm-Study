#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int res;
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};
int area[51][51];
int is_visit[51][51];

queue<pair<int, int>> shark;

void input();
void func();
bool can_move(int , int);
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void output(){
    cout<<res<<'\n';
}

void func(){
    while(!shark.empty()){
        int x = shark.front().first;
        int y = shark.front().second;
        shark.pop();
        for(int i=0; i<8; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(!can_move(xx, yy)) continue;
            if(is_visit[xx][yy]) continue;
            
            is_visit[xx][yy] = 1;
            area[xx][yy] = area[x][y] + 1;
            shark.push({xx, yy});
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            res = max(res, area[i][j]);
        }
    }
}


bool can_move(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int c; cin>>c;
            if(c) {
                shark.push({i, j});
                is_visit[i][j] = 1;
            }
        }
    }
}