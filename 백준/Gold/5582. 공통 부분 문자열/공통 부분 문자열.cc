#include <iostream>
#include <string>
using namespace std;
int dp[4001][4001];
int res = -1;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    string a, b; cin>>a>>b;
    for(int i=0; i<a.size(); ++i){
        for(int j=0; j<b.size(); ++j){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] +1;
            res = max(res, dp[i+1][j+1]);
        }
    }
    cout<<res;
    return 0;
} 
