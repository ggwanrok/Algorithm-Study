#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> graph[100001];

void input();
pair<int, int> bfs(int start);

int main() {
    input();
    // Step 1: Find the farthest node from an arbitrary starting node (e.g., node 1)
    pair<int, int> result1 = bfs(1);
    // Step 2: Find the farthest node from the farthest node found in step 1
    pair<int, int> result2 = bfs(result1.first);
    // Output the tree diameter
    cout << result2.second << endl;
    return 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (true) {
            int a, b;
            cin >> a;
            if (a == -1) break;
            cin >> b;
            graph[k].emplace_back(a, b);
        }
    }
}

pair<int, int> bfs(int start) {
    vector<int> distance(n + 1, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    int farthest_node = start;
    int max_distance = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[node] + weight;
                q.push(neighbor);
                if (distance[neighbor] > max_distance) {
                    max_distance = distance[neighbor];
                    farthest_node = neighbor;
                }
            }
        }
    }
    
    return {farthest_node, max_distance};
}
