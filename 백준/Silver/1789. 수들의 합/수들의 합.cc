#include <iostream>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n; cin>>n;
    ll target = n;
    ll res = 0;
    for(ll i=1; i<=n; i++){
        if(target-i == 0) {
            res++; 
            break;
        }
        if(target-i < 0) break;
        if(target-i > 0) res++;
        target -= i;
    }
    cout<<res<<'\n';
    return 0;
}