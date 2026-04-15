#include <bits/stdc++.h>

using namespace std;

int main(){
    int sk_win[1001];
    sk_win[1] = 1;
    sk_win[2] = 0;
    sk_win[3] = 1;
    sk_win[4] = 1;
    for(int i=5; i<=1000; i++){
        if(sk_win[i-1] && sk_win[i-3] && sk_win[i-4]){
            sk_win[i] = 0;
        }
        else{
            sk_win[i] = 1;
        }
    }
    int n; cin>>n;
    if(sk_win[n]){
        cout<<"SK"<<'\n';
    }
    else{
        cout<<"CY"<<'\n';
    }
    return 0;
}