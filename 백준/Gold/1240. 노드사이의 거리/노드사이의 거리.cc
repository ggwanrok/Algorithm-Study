#include <bits/stdc++.h>

using namespace std;

/*
n개의 도시.
n-1개의 간선.
m개의 tc.
*/

int n, tc;
int start, fin;
int dist_node[1001];
vector<pair<int, int>> v[1001];

void input();
void func();
/*
tc만큼의 수행하는 동안. start -> end 로 값을 받아서,
start로부터 end까지의 최단거리를 구하자.
(다익스트라)
*/

int main(){
    input();
    func();
    return 0;
}

void func(){
    while(tc--){
        cin>>start>>fin;
        fill(dist_node, dist_node + n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while(!pq.empty()){
            int cur_cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            for(int i=0; i<v[cur].size(); i++){
                int cost = v[cur][i].second;
                int next = v[cur][i].first;
                if(cost + cur_cost < dist_node[next]){
                    dist_node[next] = cost +cur_cost;
                    pq.push({dist_node[next],next});
                }
            }
        }
        cout<<dist_node[fin]<<'\n';
    }
}

void input(){
    cin>>n>>tc;
    
    for(int i=0; i<n-1; i++){
        int n1, n2, cost;
        cin>>n1>>n2>>cost;
        v[n1].push_back({n2, cost});
        v[n2].push_back({n1, cost});
    }
}