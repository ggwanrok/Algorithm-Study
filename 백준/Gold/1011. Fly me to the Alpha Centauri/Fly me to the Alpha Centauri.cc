#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    최대가 한번 등장할 때 : 최댓값을 n이라고 하면 최대 n^2만큼 이동
    최대가 두번 등장할 때 : 최댓값을 n이라고 하면 최대 n^2 + n만큼 이동

    거리를 계산한 뒤에 해당 거리에 루트를 씌워 몇번의 스텝을 밟아야하는지 구할 수 있다.
    */

    int tc;
    cin >> tc;
    while (tc--) {
        long long x, y;
        cin >> x >> y;
        long long d = y - x;

        long long n = (long long) sqrt(d);

        long long ans;
        if (d == n * n) ans = 2 * n - 1;
        else if (d <= n * n + n) ans = 2 * n;
        else ans = 2 * n + 1;

        cout << ans << '\n';
    }
    return 0;
}
