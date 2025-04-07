#include <bits/stdc++.h>
using namespace std;

int arr[201][201];
int temp[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> arr[i][j];

    int res = INT_MIN;

    for (int top = 0; top < n; ++top) {
        memset(temp, 0, sizeof(temp));
        for (int bottom = top; bottom < n; ++bottom) {
            for (int col = 0; col < m; ++col)
                temp[col] += arr[bottom][col];

            int sum = 0, max_sum = INT_MIN;
            for (int k = 0; k < m; ++k) {
                sum = max(temp[k], sum + temp[k]);
                max_sum = max(max_sum, sum);
            }
            res = max(res, max_sum);
        }
    }

    cout << res << '\n';
    return 0;
}
