#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[105][11];

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j != 9){
                dp[i][j] += dp[i-1][j+1];
            }
            if(j != 0){
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] %= 1000000000;
        }
    }
}

void output(){
    long long k = 0;
    for(int i=0; i<=9; i++){
        k += dp[n][i];
    }
    cout<<k%1000000000<<'\n';
}

void input(){
    cin>>n;
    dp[1][0] = 0;
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }
}