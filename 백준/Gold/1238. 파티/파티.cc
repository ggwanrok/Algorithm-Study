#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int res = 0;
int n, m, x;
vector<pair<int, int>> edge[10001];
vector<pair<int, int>> edge_rev[10001];

void input();
void func();
vector<int> dijkstra(int start, vector<pair<int, int>> graph[]);
void output();

int main() {
    input();
    func();
    output();
    return 0;
}

vector<int> dijkstra(int start, vector<pair<int, int>> graph[]) {
    vector<int> dist(n + 1, 1e9); // 노드 수(n) 기반의 거리 배열 설정
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        for (auto &next : graph[cur_node]) {
            int next_node = next.first;
            int next_cost = next.second;
            
            if (cur_cost + next_cost < dist[next_node]) {
                dist[next_node] = cur_cost + next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist;
}

void func() {
    // x에서 각 노드로 가는 최단 거리
    vector<int> dist_from_x = dijkstra(x, edge);

    // 각 노드에서 x로 돌아오는 최단 거리
    vector<int> dist_to_x = dijkstra(x, edge_rev);

    // 왕복 거리의 최대값 계산
    for (int i = 1; i <= n; i++) {
        if (dist_from_x[i] != 1e9 && dist_to_x[i] != 1e9) { // 유효한 경로만 계산
            res = max(res, dist_from_x[i] + dist_to_x[i]);
        }
    }
}

void output() {
    cout << res << '\n';
}

void input() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].push_back({to, cost});
        edge_rev[to].push_back({from, cost});
    }
}
