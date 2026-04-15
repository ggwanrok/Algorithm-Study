#include <iostream>
using namespace std;
int dp0[42];
int dp1[42];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    dp0[0] = 1;
    dp1[0] = 0;
    dp0[1] = 0;
    dp1[1] = 1;
    for(int i=2; i<=40; ++i){
        dp0[i] = dp0[i-1] + dp0[i-2];
        dp1[i] = dp1[i-1] + dp1[i-2];
    }
    for(int i=0; i<n; ++i){
        int k; cin>>k;
        cout<<dp0[k]<<" "<<dp1[k]<<'\n';
    }
    return 0;
} 
