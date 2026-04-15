#include <bits/stdc++.h>

using namespace std;

int a, b;

int c, n;

int main(){
    cin>>a>>b;
    cin>>c>>n;

    int check1, check2;
    check1 = (a <= c) ? 1 : 0;
    check2 = (a*n + b <= c*n) ? 1 : 0;

    if(check1 > 0 && check2 > 0){
        cout<<1<<'\n';
    }
    else{
        cout<<0<<'\n';
    }

    return 0;
}