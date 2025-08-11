#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;      
    cin >> N >> M;

    vector<pair<int,int>> ch(M);
    for (int i = 0; i < M; ++i) {
        int term, page;
        cin >> term >> page;
        ch[i] = {term, page};
    }

    vector<int> dp(N + 1, 0);
    for (auto [term, page] : ch) {
        for (int t = N; t >= term; --t) {
            dp[t] = max(dp[t], dp[t - term] + page);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}