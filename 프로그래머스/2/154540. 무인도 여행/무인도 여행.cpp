#include <bits/stdc++.h>

using namespace std;

bool is_in(int i, int j, int n, int m){
    if(i<0 || i>=n || j<0 || j>= m) return false;
    return true;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

vector<int> solution(vector<string> maps) {
    vector<vector<int>> area(maps.size());
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].length(); j++){
            if(maps[i][j] == 'X'){
                area[i].push_back(-1);
            }
            else{
                area[i].push_back(maps[i][j]-'0');
            }
        }
    }
    int n = area.size();
    int m = area[0].size();
    vector<vector<int>> is_visited(area.size(), vector<int>(area[0].size(), 0));
    
    vector<int> answer;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] != -1 and is_visited[i][j] == 0){
                //로직 수행
                int value = 0;
                queue<pair<int, int>> q;
                is_visited[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    int cur_x = q.front().first;
                    int cur_y = q.front().second;
                    q.pop();
                    value += area[cur_x][cur_y];
                    for(int c=0; c<4; c++){
                        int x = cur_x+dx[c];
                        int y = cur_y+dy[c];
                        if(is_in(x, y, n, m) and area[x][y] != -1 and is_visited[x][y] == 0){
                            is_visited[x][y] = 1;
                            q.push({x, y});
                        }
                    }
                }
                answer.push_back(value);
            }
        }
    }
    sort(answer.begin(), answer.end());
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}