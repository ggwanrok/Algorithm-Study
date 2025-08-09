#include <bits/stdc++.h>
using namespace std;

int cnt1, cnt2;
int dp[50];

int fib(int a){
    if(a == 1 || a == 2) {
        cnt1++;
        return 1;
    }
    else{
        return fib(a-1) + fib(a-2);
    }
}

int fibo(int a){
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=a; i++){
        cnt2++;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[a];
}

int main(){
    int n; cin>>n;
    fib(n);
    fibo(n);
    cout<<cnt1<<' '<<cnt2<<'\n';
    return 0;
}