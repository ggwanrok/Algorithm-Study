#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int c, n;
vector<int> dp;
vector<pair<int, int>> v; // (비용, 고객 수)

int main() {
    cin >> c >> n;
    dp.resize(1101, INF);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    dp[0] = 0; // 고객 0명을 유치하는 데 필요한 비용은 0

    for (auto iter : v) {
        int cost = iter.first;
        int customers = iter.second;
        for (int i = customers; i <= 1100; i++) { // 내림차순으로 갱신해야 중복 문제 없음
            dp[i] = min(dp[i], dp[i - customers] + cost);
        }
    }

    int res = INF;
    for (int i = c; i <= 1100; i++) { // 적어도 c명 이상을 유치하는 최소 비용 찾기
        res = min(res, dp[i]);
    }

    cout << res << '\n';
    return 0;
}
