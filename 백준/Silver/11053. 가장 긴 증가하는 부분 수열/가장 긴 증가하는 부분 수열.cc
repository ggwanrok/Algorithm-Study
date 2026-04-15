#include <iostream>
using namespace std;
int dp[1001];
int arr[1001];
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    int res = 0;
    for(int i=0; i<n; ++i){
        dp[i] = 1;
        for(int j=0; j<i; ++j){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    cout<<res;
    return 0;
} 
