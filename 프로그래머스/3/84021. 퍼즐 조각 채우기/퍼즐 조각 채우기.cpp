#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

/*
구역을 돌면서, 빈 칸을 만나면, 해당 지점을 0, 0으로 해서 탐색해서 빈 칸 정보를 넣어줌.
우선 빈칸 정보를 
vector<vector<pair>>> 형태에 넣어줘.
완탐을 진행하면서 빈 칸을 만나면, 해당 지점에 대해서
각 회전을 해서 넣을 수 있는가? 로 넣고 돌려.
(백트레킹을 하는거야)
우선 위치 파악부터 하자.

0 : x, y
90 : -y, x
180 : -x, -y
270 : y, -x

*/

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool can_be(vector<pair<int, int>> a, vector<pair<int, int>> b){
    if(a.size() != b.size()) return false;
    sort(a.begin(), a.end());
    for(int turn = 0; turn < 4; turn++){
        sort(b.begin(), b.end());
        if(a == b) return true;
        for(int i=0; i<b.size(); i++){
            int x = b[i].first;
            int y = b[i].second;
            b[i].first = y * -1;
            b[i].second = x;
        }
        int x = b[0].first;
        int y = b[0].second;
        for(int i=0; i<b.size(); i++){
            x = min(x, b[i].first);
            y = min(y, b[i].second);
        }
        for(int i=0; i<b.size(); i++){
            b[i].first -= x;
            b[i].second -= y;
        }
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    vector<vector<pair<int, int>>> target;
    vector<vector<int>> is_visited(table.size(), vector<int>(table.size(), 0));
    for(int i=0; i<table.size(); i++){
        for(int j=0; j<table.size(); j++){
            if(table[i][j] == 1 and is_visited[i][j] == 0){
                vector<pair<int, int>> cur_target;
                queue<pair<int, int>> q;
                q.push({i, j});
                is_visited[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    cur_target.push_back({x, y});
                    
                    for(int c=0; c<4; c++){
                        int xx = x + dx[c];
                        int yy = y + dy[c];
                        if(xx < 0 || xx >= table.size() || yy < 0 || yy >= table.size()) continue;
                        if(is_visited[xx][yy] != 0 || table[xx][yy] != 1) continue;
                        is_visited[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }
                target.push_back(cur_target);
            }
        }
    }
    //여기까지 target에 좌표 정보를 넣었음. 이제 0, 0으로 정리해야할듯.
    for(int i=0; i<target.size(); i++){
        int x = target[i][0].first;
        int y = target[i][0].second;
        for(int j=0; j<target[i].size(); j++){
            x = min(x, target[i][j].first);
            y = min(y, target[i][j].second);
        }
        for(int j=0; j<target[i].size(); j++){
            target[i][j].first -= x;
            target[i][j].second -= y;
        }
    }
    
    //0, 0으로 정리 수행. 이제 빈 공간 정보를 저장해둬야 함.
    vector<vector<pair<int, int>>> empty_place;
    
    is_visited.assign(game_board.size(), vector<int>(game_board.size(), 0));
    for(int i=0; i<game_board.size(); i++){
        for(int j=0; j<game_board.size(); j++){
            if(game_board[i][j] == 0 and is_visited[i][j] == 0){
                vector<pair<int, int>> cur_target;
                queue<pair<int, int>> q;
                q.push({i, j});
                is_visited[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    cur_target.push_back({x, y});
                    
                    for(int c=0; c<4; c++){
                        int xx = x + dx[c];
                        int yy = y + dy[c];
                        if(xx < 0 || xx >= game_board.size() || yy < 0 || yy >= game_board.size()) continue;
                        if(is_visited[xx][yy] != 0 || game_board[xx][yy] != 0) continue;
                        is_visited[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }
                empty_place.push_back(cur_target);
            }
        }
    }
    
    //여기까지 빈공간 처리 완. 이제 0, 0으로 정리해야할듯.
    for(int i=0; i<empty_place.size(); i++){
        int x = empty_place[i][0].first;
        int y = empty_place[i][0].second;
        for(int j=0; j<empty_place[i].size(); j++){
            x = min(x, empty_place[i][j].first);
            y = min(y, empty_place[i][j].second);
        }
        for(int j=0; j<empty_place[i].size(); j++){
            empty_place[i][j].first -= x;
            empty_place[i][j].second -= y;
        }
    }
    //여기까지 빈공간 및 블록들 좌표 정규화 작업 수행 완. target, empty_place
    vector<int> is_used(target.size(), 0);
    for(int i=0; i<empty_place.size(); i++){
        for(int j=0; j<target.size(); j++){
            //성립하면,
            if(is_used[j] != 1 and can_be(empty_place[i], target[j])){
                is_used[j] = 1;
                answer += target[j].size();
                break;
            }
        }
    }
    
    return answer;
}