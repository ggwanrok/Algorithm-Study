#include <iostream>
#include <cstring>
using namespace std;

int coin[21];
int dp[10001];
int target;
int n;

void clearArray(){
    for(int i=0; i<21; i++){
        coin[i] = 0;
    }
    for(int i=0; i<10001; i++){
        dp[i] = 0;
    }
}

void coinDp(){
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=target; j++){
            dp[j] = dp[j] + dp[j-coin[i]];
        }
    }
    cout<<dp[target]<<'\n';
    
}

int main(void){
    int TC;
    cin>>TC;

    while(TC--){
        cin>>n;
    clearArray();
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        coin[i] = k;
    }
    cin>>target;

    coinDp();
    }


    return 0;
}