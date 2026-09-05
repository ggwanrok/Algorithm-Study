#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
bfs를 하면서 못가는 부분에 대해서는 우선순위 큐 라벨링을 해줘.
bfs를 돌려주면서 각 지역들 라벨링을 해. 라벨링이 안되는 지역이라면 우선순위 큐에 넣어줘.
우선순위 큐에서 하나씩 빼면서 라벨링을 더해주면 됨. 결국 다 뽑아주게 되면 결국 하나의 덩어리가 되어있을거임.
그리고 우선순위 큐에서 나오는 차이를 가지고 스윽이 되는겨.
*/

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// 최상위 부모 찾기
int get_par(int idx, vector<int>& uf){
    if(uf[idx] == idx) return idx;
    return uf[idx] = get_par(uf[idx], uf);
}


// 두 영역 연결
bool union_par(int a, int b, vector<int>& uf){
    a = get_par(a, uf);
    b = get_par(b, uf);

    // 이미 같은 영역
    if(a == b) return false;

    uf[b] = a;
    return true;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    
    int n = land.size();

    priority_queue<
        tuple<int, int, int, int, int>,
        vector<tuple<int, int, int, int, int>>,
        greater<>
    > pq; // costdiff, x1, y1, x2, y2

    vector<vector<int>> is_visited(n, vector<int>(n, 0));
    vector<vector<int>> par(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            par[i][j] = i*n+j;
        }
    }

    // BFS로 영역 라벨링
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

                        // 같은 영역이면 시작점의 번호로 라벨링
                        par[xx][yy] = i*n+j;
                    }
                    else{
                        pq.push({
                            abs(land[xx][yy] - land[x][y]),
                            x, y, xx, yy
                        });
                    }
                }
            }
        }
    }


    //union-find
    vector<int> uf(n*n);

    for(int i=0; i<n*n; i++){
        uf[i] = par[i/n][i%n];
    }


    while(!pq.empty()){

        auto pq_top = pq.top();
        pq.pop();

        int cost = get<0>(pq_top);

        pair<int, int> a1 = {
            get<1>(pq_top),
            get<2>(pq_top)
        };

        pair<int, int> a2 = {
            get<3>(pq_top),
            get<4>(pq_top)
        };


        int idx1 = a1.first*n + a1.second;
        int idx2 = a2.first*n + a2.second;


        // 서로 다른 영역이면 연결
        if(union_par(idx1, idx2, uf)){
            answer += cost;
        }
    }

    return answer;
}