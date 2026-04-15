#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> tree[10005]; // 간선정보

vector<int> leaf;

void input();
void func();
pair<int, int> bfs(int);

int main(){
    input();
    func();
    return 0;
}

pair<int, int> bfs(int start){
    vector<int> dist(n+1, -1);
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;
    int max_dist = 0;
    int max_node = start;
    while(!q.empty()){
        int node = q.front().first;
        int cost = q.front().second;
        q.pop();
        for(auto& edge : tree[node]){
            int next_node = edge.first;
            int next_cost = edge.second;
            if(dist[next_node] == -1){
                dist[next_node] = cost + next_cost;
                q.push({next_node, cost + next_cost});
                if(max_dist < dist[next_node]){
                    max_dist = dist[next_node];
                    max_node = next_node;
                }
            }
        }
    }
    return {max_node, max_dist};
}

void func(){
    //leaf 벡터를 기준으로 진행.
    int first_point = bfs(1).first;
    cout<<bfs(first_point).second<<'\n';
}

void input(){
    cin>>n;
    for(int i=1; i<n; i++){
        int from, to, cost;
        cin>>from>>to>>cost;
        tree[from].push_back({to, cost});
        tree[to].push_back({from, cost});
    }
}