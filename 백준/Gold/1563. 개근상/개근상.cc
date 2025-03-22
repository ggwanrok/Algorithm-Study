#include <bits/stdc++.h>
using namespace std;

int n;
const int MOD = 1000000;

long long arr[1001][2][3]; // (일차, 총 지각횟수, 연속결석일수)

void good(int, int);
void late(int);
void no_show(int);

void func() {
    arr[1][0][0] = 1; // 첫날 출석
    arr[1][1][0] = 1; // 첫날 지각
    arr[1][0][1] = 1; // 첫날 결석
    arr[1][1][1] = 0; // 가능성 없음

    for (int i = 2; i <= n; i++) {
        good(i, 0);
        good(i, 1);
        late(i);
        no_show(i);
    }

    int res = 0;
    for (int l = 0; l <= 1; l++) {
        for (int a = 0; a <= 2; a++) {
            res = (res + arr[n][l][a]) % MOD;
        }
    }

    cout << res << '\n';
}

void good(int i, int l) {
    arr[i][l][0] = (arr[i][l][0]
        + arr[i-1][l][0]
        + arr[i-1][l][1]
        + arr[i-1][l][2]) % MOD;
}

void late(int i) {
    arr[i][1][0] = (arr[i][1][0]
        + arr[i-1][0][0]
        + arr[i-1][0][1]
        + arr[i-1][0][2]) % MOD;
}

void no_show(int i) {
    arr[i][0][1] = (arr[i][0][1] + arr[i-1][0][0]) % MOD;
    arr[i][0][2] = (arr[i][0][2] + arr[i-1][0][1]) % MOD;
    arr[i][1][1] = (arr[i][1][1] + arr[i-1][1][0]) % MOD;
    arr[i][1][2] = (arr[i][1][2] + arr[i-1][1][1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    func();

    return 0;
}
