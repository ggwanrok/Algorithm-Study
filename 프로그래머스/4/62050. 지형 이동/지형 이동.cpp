#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
bfs를 하면서 못가는 부분에 대해서는 우선순위 큐 라벨링을 해줘.
bfs를 돌려주면서 각 지역들 라벨링을 해. 라벨링이 안되는 지역이라면 우선순위 큐에 넣어줘.
우선순위 큐에서 하나씩 뺴면서 라벨링을 더해주면 됨. 결국 다 뽑아주게 되면 결국 하나의 덩어리가 되어있을거임.
그리고 우선순위 큐에서 나오는 차이를 가지고 스윽이 되는겨.
*/                

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    
    int n = land.size();
    priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<>> pq; //costdiff, x1, y1, x2, y2
    vector<vector<int>> is_visited(n, vector<int>(n, 0));
    vector<vector<int>> par(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            par[i][j] = i*n+j;
        }
    }
    for(int i=0; i<land.size(); i++){
        for(int j=0; j<land.size(); j++){
            if(is_visited[i][j]) continue;
            queue<pair<int, int>> q;
            is_visited[i][j] = 1;
            q.push({i, j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int c=0; c<4; c++){
                    int xx = x + dx[c];
                    int yy = y + dy[c];
                    if(xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
                    if(is_visited[xx][yy]) continue;
                    if(abs(land[xx][yy] - land[x][y]) <= height){
                        is_visited[xx][yy] = 1;
                        q.push({xx, yy});
                        par[xx][yy] = i*n+j;
                    }
                    else{
                        pq.push({abs(land[xx][yy]-land[x][y]), x, y, xx, yy});
                    }
                }
            }
        }
    }
    //pq를 가지고 이제 모든 놈들 다 엮어주기
    while(!pq.empty()){
        auto pq_top = pq.top();
        pq.pop();
        int cost = get<0>(pq_top);
        pair<int, int> a1 = {get<1>(pq_top), get<2>(pq_top)};
        pair<int, int> a2 = {get<3>(pq_top), get<4>(pq_top)};
        int par1 = par[a1.first][a1.second];
        int par2 = par[a2.first][a2.second];
        if(par1 == par2) continue;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(par[i][j] == par2) 
                {par[i][j] = par1;}       
            }
        }
        answer += cost;
    }
        
    
    
    return answer;
}