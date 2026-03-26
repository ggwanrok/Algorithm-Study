#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int L, N, M;
vector<vector<int>> info;
int memo[41][121][121];

int dfs(int idx, int a, int b) {
    if (a >= N || b >= M) return INF;
    if (idx == L) return 0;

    int &ret = memo[idx][a][b];
    if (ret != -1) return ret;

    int da = info[idx][0];
    int db = info[idx][1];

    ret = INF;
    ret = min(ret, da + dfs(idx + 1, a + da, b));   // A가 훔침
    ret = min(ret, dfs(idx + 1, a, b + db));        // B가 훔침

    return ret;
}

int solution(vector<vector<int>> _info, int n, int m) {
    info = _info;
    N = n;
    M = m;
    L = info.size();

    memset(memo, -1, sizeof(memo));

    int ans = dfs(0, 0, 0);
    return (ans >= INF ? -1 : ans);
}