#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;

vector<ll> v;
vector<ll> mod;

int main(){
    cin>>n>>m;
    v.resize(n+1, 0);
    mod.resize(m+1, 0);
    for(int i=1; i<=n; i++){
        int k; cin>>k;
        ll idx = (v[i-1] + k) % m;
        v[i] = idx;
        mod[idx]++;
    }
    ll res = 0;
    
    res += mod[0];
    for(int i=0; i<m; i++){
        if(mod[i] <= 0) continue;
        res += (mod[i] * (mod[i]-1))/2;
    }
    cout<<res<<'\n';
    return 0;
}