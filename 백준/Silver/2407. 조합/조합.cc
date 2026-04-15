#include <iostream>
#define MOD 1000000000000000

using namespace std;

int n, m;
long long dp1[101][101], dp2[101][101];

int main() {
	cin >> n >> m;

	dp1[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp1[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - 1];
			dp2[i][j] = dp2[i - 1][j] + dp2[i - 1][j - 1];

			dp2[i][j] += dp1[i][j] / MOD;
			dp1[i][j] %= MOD;
		}
	}

	if (dp2[n][m] == 0) {
		cout << dp1[n][m] << '\n';
	}
	else {
		cout << dp2[n][m] << dp1[n][m] << '\n';
	}
}

