#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001]; // dp[i][j] : (i, j)에서 끝나는 정사각형의 최대 한 변 길이
int res = 0;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
}

void func() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) { // 1인 경우에만 정사각형 가능
                if (i == 0 || j == 0) dp[i][j] = 1; // 가장자리(첫 행, 첫 열)에서는 최대 크기 1
                else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                res = max(res, dp[i][j]); // 최대 변 길이 갱신
            }
        }
    }
    cout << res * res << '\n'; // 넓이 출력
}

int main() {
    input();
    func();
    return 0;
}
