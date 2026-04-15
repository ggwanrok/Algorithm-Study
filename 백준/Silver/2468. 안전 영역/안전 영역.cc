#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

/*
hei -> 1 ~ 100
n -> 2 ~ 100
=> just bfs about off depth*/

int n;
int arr[101][101];
int temp[101][101];
int is_visited[101][101];
int max_depth;
int res;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input(){
    cin>>n;
    max_depth = 0;
    res = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            max_depth = max(max_depth, arr[i][j]);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    //doing in all of about depth
    for(int dep=0; dep<=max_depth; dep++){
        memset(temp, 0, sizeof(temp));
        memset(is_visited, 0, sizeof(is_visited));
        //set temp about each depth
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(arr[r][c] > dep) temp[r][c] = 1;
            }
        }
        //land : 1 
        //water : 0
        queue<pair<int, int>> q;
        int cur_res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j] == 0 || is_visited[i][j] == 1) continue;
                cur_res++;
                is_visited[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    int fir = q.front().first;
                    int sec = q.front().second;
                    q.pop();
                    for(int loop=0; loop<4; loop++){
                        int x = fir+dx[loop];
                        int y = sec+dy[loop];
                        if(x < 0 || y < 0 || x > n || y > n) continue;
                        if(temp[x][y] == 0 || is_visited[x][y] == 1) continue;
                        is_visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
        res = max(res ,cur_res);
    }
    cout<<res<<'\n';
    return 0;
}