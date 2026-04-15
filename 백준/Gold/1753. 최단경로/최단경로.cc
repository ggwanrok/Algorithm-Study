#include <bits/stdc++.h>
#define INF 2000000
using namespace std;

int v, e;
int start;
vector<pair<int, int>> cost[20002];
int going_cost[20002];
bool visited[20002];

void input();
void func();
void output();

int main(void) {
    input();
    func();
    output();
    return 0;
}

void input() {
    cin >> v >> e;
    cin >> start;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a].push_back({b, c});
    }
    for (int i = 1; i <= v; i++) {
        going_cost[i] = INF;
        visited[i] = false;
    }
    going_cost[start] = 0;
}

void func() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node]) continue;
        visited[current_node] = true;

        for (auto edge : cost[current_node]) {
            int next_node = edge.first;
            int next_cost = edge.second;

            if (going_cost[next_node] > current_cost + next_cost) {
                going_cost[next_node] = current_cost + next_cost;
                pq.push({going_cost[next_node], next_node});
            }
        }
    }
}

void output() {
    for (int i = 1; i <= v; i++) {
        if (going_cost[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << going_cost[i] << '\n';
        }
    }
}
