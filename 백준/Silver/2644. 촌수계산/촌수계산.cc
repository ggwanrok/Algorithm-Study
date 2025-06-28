#include <bits/stdc++.h>
using namespace std;

int n, tar_1, tar_2, m;
vector<int> adj[101];
bool visited[101];
int answer = -1;

void dfs(int cur, int depth) {
    if (cur == tar_2) {
        answer = depth;
        return;
    }
    visited[cur] = true;

    for (int next : adj[cur]) {
        if (!visited[next]) {
            dfs(next, depth + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> tar_1 >> tar_2 >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // 양방향 연결
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(tar_1, 0);
    cout << answer << '\n';
    return 0;
}