#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; 
    cin >> N >> K;

    vector<int> g(N+1), s(N+1), b(N+1);

    for (int i = 0; i < N; ++i) {
        int id; 
        cin >> id >> g[id] >> s[id] >> b[id];
    }

    int rank = 1;
    for (int id = 1; id <= N; ++id) {
        if (g[id] > g[K] ||
           (g[id] == g[K] && s[id] > s[K]) ||
           (g[id] == g[K] && s[id] == s[K] && b[id] > b[K])) {
            ++rank;
        }
    }

    cout << rank << '\n';
    return 0;
}
