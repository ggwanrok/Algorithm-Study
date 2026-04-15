#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long  n, p; cin>>n>>p;
    long long  t = 1;
    for(long long  i=1; i<=n; ++i){
        if(t>p){
            t = t%p;
        }
        t = t *i;
    }
    
    cout<< t%p <<'\n';
    return 0;
}