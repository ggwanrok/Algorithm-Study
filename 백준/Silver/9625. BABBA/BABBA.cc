#include <bits/stdc++.h>

using namespace std;

int a[50];
int b[50];

int main(){
    a[0] = 1;
    a[1] = 0;
    b[0] = 0;
    b[1] = 1;
    int n; cin>>n;
    for(int i=2; i<=n; i++){
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-1] + b[i-2];
    }
    cout<<a[n]<<' '<<b[n]<<'\n';
    return 0;
}