#include <bits/stdc++.h>

using namespace std;

int arr[2][100001];
int dp[2][100001];

int n;
int tc;
int res;

void input();
void func();

int main(void){
    cin>>tc;
    while(tc--){
        input();
        func();
    }
    return 0;
}

void func(){
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[0][1] = arr[0][1] + arr[1][0];
    dp[1][1] = arr[1][1] + arr[0][0];
    for(int j=2; j<n; j++){
        for(int i=0; i<2; i++){
            int cur_max = 0;
            if(i == 0){
                cur_max = dp[0][j-2];
                if(cur_max < dp[1][j-2]) cur_max = dp[1][j-2];
                if(cur_max < dp[1][j-1]) cur_max = dp[1][j-1];
            }
            else{
                cur_max = dp[0][j-2];
                if(cur_max < dp[1][j-2]) cur_max = dp[1][j-2];
                if(cur_max < dp[0][j-1]) cur_max = dp[0][j-1];
            }
            dp[i][j] = arr[i][j] + cur_max;
        }
    }
    res = dp[0][n-2];
    if(res < dp[0][n-1]) res = dp[0][n-1];
    if(res < dp[1][n-2]) res = dp[1][n-2];
    if(res < dp[1][n-1]) res = dp[1][n-1];
    cout<<res<<'\n';
}

void input(){
    cin>>n;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
            dp[i][j] = 0;
            res = 0;
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            int k;
            cin>>k;
            arr[i][j] = k;
        }
    }
}