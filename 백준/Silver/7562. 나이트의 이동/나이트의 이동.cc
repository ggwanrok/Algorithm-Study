//start : 16 : 40
//테스트 케이스가 주어진다.
//체스판의 크기가 주어진다.
//시작위치가 주어진다.
//목표지점이 주어진다.

//최소이동 도착횟수는?
//->최소로 도달하는 최초의 경우를 찾아야 하기에, 이는 bfs를 이용하자.

#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int is_visited[301][301];

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void clean_array(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
            is_visited[i][j] = 0;
        }
    }
}

bool is_in(int n, int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

int main(){ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int n; 
        cin>>n;
        clean_array(n);
        pair<int, int> start;
        cin>>start.first>>start.second;
        pair<int, int> target;
        cin>>target.first>>target.second;

        //start 좌표를 시작으로, 넘어갈 수 있는 경로에 대해서,
        //방문처리가 안되어있다면 방문처리를 하고 넣어준다.
        queue<pair<int, int>> q;
        is_visited[start.first][start.second] = 1;
        q.push({start.first, start.second});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == target.first && y == target.second){
                cout<<arr[x][y]<<'\n';
                break;
            }
            for(int i=0; i<8; i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(is_in(n, xx, yy) && is_visited[xx][yy] == 0){
                    is_visited[xx][yy] = 1;
                    arr[xx][yy] = arr[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }

    return 0;
}
//end : 16 : 55