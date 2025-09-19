/*
1 <-> 2 의 lcs : s1
s1 <-> 3 의 lcs : res

s1 후보군을 모두 벡터에 넣고 순회하며 돌려야할듯.

-> 이건 s1 이 1, 2의 긴 녀석들만 가지고 있다는 것에 오류가 발생해버리네.

1, 2, 3을 동시에 돌려야 하는 구조구나.
*/
#include <bits/stdc++.h>

using namespace std;

int dp[101][101][101];
string a, b, c;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;

    int len_a = a.length();
    int len_b = b.length();
    int len_c = c.length();

    for(int i = 1; i <= len_a; i++){
        for(int j = 1; j <= len_b; j++){
            for(int k = 1; k <= len_c; k++){
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
    }

    cout << dp[len_a][len_b][len_c] << '\n';
    return 0;
}