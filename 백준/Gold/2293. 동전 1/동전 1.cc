#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> coin;
vector<int> dp;

void input();
void func();

int main(){
    input();
    func();
    return 0;
}

void func(){
    for(int i=0; i<n; i++){
        for(int c = coin[i]; c<=k; c++){
            dp[c] += dp[c-coin[i]];
        }
    }
    cout<<dp[k]<<'\n';
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    dp.resize(k+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        int co; cin>>co;
        coin.push_back(co);
    }
}