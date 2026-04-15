#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin>>n>>k;
    int t = min(k, n-k);
    int c1 = 1; int c2 = 1;
    for(int i=n; i>t; --i){
        c1 *= i;
        c2 *= (n-i+1);
    }
    cout<<c1/c2<<'\n';
}
