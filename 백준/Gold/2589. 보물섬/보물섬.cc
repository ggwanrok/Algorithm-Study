#include <bits/stdc++.h>

using namespace std;

/*
중복방문을 허용치 않음 -> bfs 해라.
아닌데, 방문처리는 해야하지만, 결국 가장 멀리 가는 모든 경우를 따녀야 한다.
모든 좌표를 시작점으로 하여, 모든 경로를 다 따져봐야하는 문제 같음.
이건 완전탐색을 해야하는듯.
*/

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<char>> area;
int n, m;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    area.resize(n, vector<char>(m));
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<m; j++){
            area[i][j] = s[j];
        }
    }
    
    /*
    아니야 근데, 최단거리긴 하니깐, bfs로 가는게 맞는 것 같다.
    */

    int res = -1;
    vector<vector<int>> is_visited(n, vector<int>(m, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] == 'W') continue;
            is_visited.assign(n, vector<int>(m, 0));
            int dist = 0;
            queue<tuple<int, int, int>> q;
            is_visited[i][j] = 1;
            q.push({i, j, 0});
            while(!q.empty()){
                int row = get<0>(q.front());
                int col = get<1>(q.front());
                int dist = get<2>(q.front());
                res = max(res, dist);
                q.pop();
                for(int c=0; c<4; c++){
                    int x = row + dx[c];
                    int y = col + dy[c];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(is_visited[x][y] == 0 and area[x][y] == 'L'){
                        is_visited[x][y] = 1;
                        q.push({x, y, dist+1});
                    }
                }
            }
        }
    }

    cout<<res<<'\n';

    return 0;
}