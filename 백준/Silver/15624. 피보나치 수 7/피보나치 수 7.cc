#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll solution(ll i);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin>>n;
    cout<<solution(n)<<'\n';

    return 0;
}



ll solution(ll i){
    if(i == 0 || i == 1) return i;
    ll fibo[1000001];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int idx=2; idx<=i; idx++){
        fibo[idx] = (fibo[idx-1] + fibo[idx-2]) % mod;
    }

    return fibo[i]%mod;
}