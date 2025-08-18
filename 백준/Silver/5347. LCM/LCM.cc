#include <iostream>
#define ll long long 
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll n;

int main(){
    cin>>n;
    while(n--){
        ll var1, var2;
        cin>>var1>>var2;
        if(var1 < var2){
            ll tmp = var1;
            var1 = var2;
            var2 = tmp;
        }
        ll div = gcd(var1, var2);
        long long res = (var1 * var2) / div;
        cout<<res<<'\n';
    }
    return 0;
}