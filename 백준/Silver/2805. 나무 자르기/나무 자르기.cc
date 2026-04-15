#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> v;
ll f(ll x){
    ll ret=0;
    for(ll i=0; i<v.size(); ++i){
        ret+=max(0LL,v[i]-x); // 둘 중 큰값
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; ll m; cin>>n>>m;
    for(int i=0; i<n; ++i){
    ll h; cin>>h;
    v.push_back(h);
    }
    ll lo=0, hi=1e9+1;
    while(lo<hi-1){
        ll mid=(lo+hi)/2;
        if(f(mid) >= m){
            lo=mid;
        }
        else if(f(mid) < m){
            hi=mid;
        }
    }
    cout << lo << '\n';
}