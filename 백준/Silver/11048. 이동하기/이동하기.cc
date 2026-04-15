#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];


void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int k; cin>>k;
            arr[i][j] = k;
        }
    }
}

void func(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int sum_val = max(dp[i-1][j], max(dp[i-1][j-1], dp[i][j-1]));
            dp[i][j] = arr[i][j] + sum_val;
        }
    }
    cout<<dp[n][m]<<'\n';
}

int main(){
    input();
    func();
    return 0;
}