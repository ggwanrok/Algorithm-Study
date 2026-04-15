#include <iostream>
using namespace std;
int dp[100001];
int co[100001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n, k; cin>>n>>k;
    for(int i=1; i<=n; ++i){
        cin>>co[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=co[i]; j<=k; ++j){
            if(j-co[i] == 0 || dp[j-co[i]] !=0){
                if(dp[j] == 0){
                    dp[j] = dp[j-co[i]] +1;
                }
                else{
                    dp[j] = min(dp[j], dp[j-co[i]]+1);
                }
            }
        }
    }
    if(k != 0 && dp[k] == 0){
        cout<<-1;
    }
    else{
        cout<<dp[k];
    }
    return 0;
} 
