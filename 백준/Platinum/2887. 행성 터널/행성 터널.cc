#include <bits/stdc++.h>
using namespace std;

int n;
vector<array<int, 3>> coords; // (x, y, z)
vector<tuple<int, int, int>> edges;  // (cost, a, b)

int parent[100001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    coords.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        coords[i] = {x, y, z};
        parent[i] = i; // 유니온 파인드 초기화
    }

    // x, y, z 좌표 각각 정렬 후 인접 행성 간 간선 추가
    for (int dim = 0; dim < 3; dim++) {
        vector<pair<int, int>> temp; // (값, 인덱스)
        for (int i = 0; i < n; i++) {
            int val = coords[i][dim]; // tuple → array 변경
            temp.push_back({val, i});
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n - 1; i++) {
            int cost = abs(temp[i].first - temp[i + 1].first);
            int a = temp[i].second;
            int b = temp[i + 1].second;
            edges.push_back({cost, a, b});
        }
    }

    // 간선 정렬 후 MST 구성 (Kruskal)
    sort(edges.begin(), edges.end());
    long long totalCost = 0;
    int usedEdges = 0;
    for (auto cur : edges) {
        int cost = get<0>(cur);
        int a = get<1>(cur);
        int b = get<2>(cur);
        if (merge(a, b)) {
            totalCost += cost;
            usedEdges++;
            if (usedEdges == n - 1) break;
        }
    }

    cout << totalCost << '\n';
    return 0;
}
