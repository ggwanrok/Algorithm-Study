
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Process
    const int MAX = 100;
    int dp[MAX+1][MAX+1][2];
    memset(dp, 0, sizeof(dp));

    dp[1][0][0] = dp[1][0][1] = 1;
    for (int i=2; i<=MAX; i++) {
        for (int j=0; j<=i; j++) {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] + ((j > 0) ? dp[i-1][j-1][1] : 0);
        }
    }

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        // Process
        int ans = dp[n][k][0] + dp[n][k][1];
        v.push_back(ans);


    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}
