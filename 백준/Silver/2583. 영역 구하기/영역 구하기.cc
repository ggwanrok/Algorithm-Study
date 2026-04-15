#include <bits/stdc++.h>

using namespace std;

void solution(int n, int m, int k, const vector<vector<int>> & ract_area);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    vector<vector<int>> ract_area;
    cin>>n>>m>>k;
    ract_area.resize(k);
    for(int i=0; i<k; i++){
        ract_area[i].resize(4);
    }
    for(int i=0; i<k; i++){
        for(int j=0; j<4; j++){
            cin>>ract_area[i][j];
        }
    }

    solution(n, m, k, ract_area);


    return 0;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool can_move_to_here(int x, int y, int n, int m){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}



void solution(int n, int m, int k, const vector<vector<int>> &ract_area){
    vector<vector<int>> area;
    vector<vector<int>> is_visited;

    vector<int> res;

    area.resize(n);
    is_visited.resize(n);
    for(int i=0; i<n; i++){
        area[i].resize(m, 0);
        is_visited[i].resize(m, 0);
    }

    for(auto row : ract_area){
        int start_x = row[0], end_x = row[2];
        int start_y = row[1], end_y = row[3];
        for(int i=start_y; i<end_y; i++){
            for(int j=start_x; j<end_x; j++){
                area[i][j] = 1;
            }
        }
    }

    //area를 통한 0인 영역 bfs 를 진행하여 영역 크기 및 라벨링 해주기.
    int label = 0;
    queue<pair<int, int>> waiting_queue;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(area[i][j] == 0 && is_visited[i][j] == 0){
                //라벨링 및 방문처리 + do bfs
                is_visited[i][j] = 1;
                area[i][j] = ++label;
                int label_size = 1;
                waiting_queue.push({i, j});
                while(!waiting_queue.empty()){
                    int x = waiting_queue.front().first;
                    int y = waiting_queue.front().second;
                    waiting_queue.pop();
                    for(int c=0; c<4; c++){
                        int xx = x + dx[c];
                        int yy = y + dy[c];
                        if(can_move_to_here(xx, yy, n, m) && area[xx][yy] == 0 &&is_visited[xx][yy] == 0){
                            is_visited[xx][yy] = 1;
                            area[xx][yy] = label;
                            label_size++;
                            waiting_queue.push({xx, yy});
                        }
                    }
                }

                res.push_back(label_size);

            }
        }
    }
    

    sort(res.begin(), res.end());

    cout<<res.size()<<'\n';
    for(auto cur : res){
        cout<<cur<<' ';
    }
    cout<<'\n';

}