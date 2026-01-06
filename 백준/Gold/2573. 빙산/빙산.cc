#include <bits/stdc++.h>

using namespace std;

//all about after every year,
//that is not a problem for search blocks because there 

int solution(int n, int m, vector<vector<int>> &area);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> area;
    area.resize(n);
    for(int i=0; i<n; i++){
        area[i].resize(m);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>area[i][j];
        }
    }

    int res = solution(n, m, area);

    cout<<res<<'\n';

    return 0;
}

/*
사용할 변수.
- 입력데이터 받을 놈들.
- set의 형태로 땅정보를 저장하는 pair 저장
- area에 각 땅이 바다와 접하는 총 갯수를 저장하는 배열이 필요

동작 순서

1. 라벨링 진행 : 더 녹아내리기 전에 이미 다 지워졌는지 확인하기. 그렇다면 종료
2-1. set 정보를 참고하여 순회하며 땅정보만큼 녹아내리도록 진행
2-2. set이 깎아내리다보면, 다 녹아내리는 좌표들을 따로 저장해두기.
3-1. 저장된 다 녹아내린 지점들에 대해서 인근 대륙들에 저장 작업 해주기.
3-2. 다 독아내린 지점에 대해서 set에서 제거해주기
*/

bool check_sea(int a, int b, int n, int m){
    if(a < 0 || a >= n || b < 0 || b >= m) return false;
    return true;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solution(int n, int m, vector<vector<int>> &area){
    int answer = 0;
    //빙산 좌표
    set<pair<int, int>> ice;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] != 0){
                ice.insert({i, j});
            }
        }
    }
    //녹아내리는 양 정보
    vector<vector<int>> nei_sea;
    nei_sea.resize(n);
    for(int i=0; i<n; i++){
        nei_sea[i].resize(m, 0);
    }
    for(auto cur:ice){
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++){
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];
            if(check_sea(nxt_x, nxt_y, n, m) && area[nxt_x][nxt_y] == 0) nei_sea[x][y]++;
        }
    }

    while(!ice.empty()){
        //라벨링
        int label = 0;
        int is_visited[301][301];
        memset(is_visited, 0, sizeof(is_visited));
        queue<pair<int, int>> labeling_queue;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(area[i][j] > 0 && (ice.find({i, j}) != ice.end()) && is_visited[i][j] == 0){ //얼음이 존재했고, 현재도 존재하면서, 최초 방문이라면
                    is_visited[i][j] = ++label;
                    labeling_queue.push({i, j});
                }
                while(!labeling_queue.empty()){ //do bfs
                    int x = labeling_queue.front().first;
                    int y = labeling_queue.front().second;
                    labeling_queue.pop();
                    for(int i=0; i<4; i++){
                        int nxt_x = x + dx[i];
                        int nxt_y = y + dy[i];
                        if(check_sea(nxt_x, nxt_y, n, m) && area[nxt_x][nxt_y] > 0 && is_visited[nxt_x][nxt_y] == 0){
                            is_visited[nxt_x][nxt_y] = label;
                            labeling_queue.push({nxt_x, nxt_y});
                        }
                    }
                }
            }
        }
        if(label > 1) break;

        answer++;

        //녹이기 작업 진행
        vector<pair<int, int>> deleted_ice;
        for(auto cur:ice){
            int x = cur.first;
            int y = cur.second;
            area[x][y] = (0 < area[x][y] - nei_sea[x][y]) ? area[x][y] - nei_sea[x][y] : 0;
            if(area[x][y] == 0) deleted_ice.push_back({x, y});
        }
        //녹은 여파 후처리
        for(auto cur:deleted_ice){
            int x = cur.first;
            int y = cur.second;
            for(int i=0; i<4; i++){
                int nei_x = x + dx[i];
                int nei_y = y + dy[i];
                if(check_sea(nei_x, nei_y, n, m)){
                    nei_sea[nei_x][nei_y]++;
                }
            }
            ice.erase({x, y});
        }
        deleted_ice.clear();

        if(ice.empty()) return 0;
    }

    return answer;
}