#include <bits/stdc++.h>

using namespace std;


int n, chairs;
vector<pair<int, int>> politic;  // {의석 수, 정당 번호}

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	cout.tie(nullptr);

	chairs = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		politic.emplace_back(a, i);
		chairs += a;
	}
    
	sort(politic.begin(), politic.end(), greater<>());
}

void func(){
	vector<int> dp[100001];
	int ans = 0;
	dp[0].push_back(-1);

	for (const auto &info : politic) {
		for (int base = chairs / 2; base >= 0; base--) {
			int after = info.first + base;
			if (!dp[base].empty() && dp[after].empty()) {
				ans = max(ans, after);
				dp[after] = dp[base];
				dp[after].push_back(info.second);
			}
		}
	}

	cout << dp[ans].size() - 1 << "\n";
	for (const auto &i : dp[ans]) if (i > 0) cout << i << " ";
}

int main() {
	input();
    func();
}