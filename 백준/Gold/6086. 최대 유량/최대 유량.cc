

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_NODES = 52; // 노드 최대 수 ('A'-'Z'와 'a'-'z'를 포함)

int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];

// 노드를 인덱스로 변환 ('A'-'Z'는 0-25, 'a'-'z'는 26-51)
int toIndex(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

bool bfs(int source, int sink) {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(source);
    parent[source] = source;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next = 0; next < MAX_NODES; ++next) {
            if (parent[next] == -1 && capacity[current][next] - flow[current][next] > 0) {
                parent[next] = current;
                if (next == sink) return true;
                q.push(next);
            }
        }
    }
    return false;
}

int edmondsKarp(int source, int sink) {
    int maxFlow = 0;

    while (bfs(source, sink)) {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n;
    cin >> n;

    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));

    for (int i = 0; i < n; ++i) {
        char u, v;
        int cap;
        cin >> u >> v >> cap;
        int ui = toIndex(u);
        int vi = toIndex(v);
        capacity[ui][vi] += cap; // 중복 에지의 경우 용량을 합산
        capacity[vi][ui] += cap; // 양방향 그래프로 처리
    }

    int source = toIndex('A');
    int sink = toIndex('Z');

    cout << edmondsKarp(source, sink) << endl;

    return 0;
}
