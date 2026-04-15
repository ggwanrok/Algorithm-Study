#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dp;

int main(){
    /*
    구조적으로 제곱수들은 제곱수들의 합을 통해서
    더 큰 제곱수를 나타내기 때문에,
    우선 가장 큰 수부터 빼곡하게 채운다면 되는 문제이다.
    라고 생각했지만,
    그리디로 풀면 반례가 있었다.
    그래서 디피로 풀어야하는 문제인 것 같다.
    */
    cin>>n;
    dp.resize(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1; i*i<=n; i++){
        int k = i*i;
        for(int j = k; j<=n; j++){
            dp[j] = min(dp[j], dp[j-k]+1);
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}