#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<ll> fibo;
    vector<ll> len;
    fibo.push_back(0);
    fibo.push_back(1);

    int idx = fibo.size();
    while(idx <= 81){
        fibo.push_back(fibo[idx-1] + fibo[idx-2]);
        idx++;
    }

    int n; cin>>n;
    ll res = 0;
    res += (fibo[n]*2 + fibo[n+1]*2);

    cout<<res<<'\n';

    return 0;
}