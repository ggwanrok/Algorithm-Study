#include <bits/stdc++.h>
using namespace std;

int res = INT_MAX;
int v, e;
vector<pair<int,int>> edge[801]; //[부터], {까지, 비용}

int dij[801];

int ev_1;
int ev_2;

void input();
void func();
int shortest_dist(int, int);
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    int roop = 2;
    while (roop--) {
        int t = ev_1;
        ev_1 = ev_2;
        ev_2 = t;

        int dist = shortest_dist(1, ev_1);
        if (dist == INT_MAX) continue;  

        int ev1_to_ev2 = shortest_dist(ev_1, ev_2);
        if (ev1_to_ev2 == INT_MAX) continue;  
        dist += ev1_to_ev2;

        int ev2_to_v = shortest_dist(ev_2, v);
        if (ev2_to_v == INT_MAX) continue;  
        dist += ev2_to_v;

        res = min(res, dist);

        
    }
}

int shortest_dist(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v + 1, INT_MAX);
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr_node]) continue;

        for (auto& edge_info : edge[curr_node]) {
            int next_node = edge_info.first;
            int weight = edge_info.second;

            if (dist[next_node] > dist[curr_node] + weight) {
                dist[next_node] = dist[curr_node] + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    return dist[end];
}


void input(){
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    for(int i=1; i<=v; i++){
        dij[i] = INT_MAX;
    }
    cin>>ev_1>>ev_2;
}

void output(){
    if(res == INT_MAX) cout<<-1<<'\n';
    else cout<<res<<'\n';
}