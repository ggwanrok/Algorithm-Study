#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, cost;
    
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int v, e;
int res;
vector<Edge> edges;

void input();
void func();
void output();


int main() {
    input();
    func();
    output();
    return 0;
}

void func() {
    //각자가 루트인 그룹을 가지게 한다.
    vector<int> parent(v + 1);
    for (int i = 1; i <= v; ++i) {
        parent[i] = i;
    }
    
    sort(edges.begin(), edges.end());
    
    for (const auto& edge : edges) {
        int from = edge.from;
        int to = edge.to;
        int cost = edge.cost;

        if (parent[from] != parent[to]) { //서로의 그룹이 다르다면, 그룹을 합치고 해당 간선을 더해준다.
            res += cost;
            
            // 모든 노드들을 같은 그룹으로 설정
            int old_parent = parent[to];
            for (int i = 1; i <= v; ++i) {
                if (parent[i] == old_parent) {
                    parent[i] = parent[from];
                }
            }
        }
    }
}

void input() {
    cin >> v >> e;
    edges.clear();
    for (int i = 0; i < e; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.emplace_back(from, to, cost);
    }
}

void output(){
    cout << res << '\n';
}