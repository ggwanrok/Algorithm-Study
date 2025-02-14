#include <iostream>
#define SIZE 100000
#define ll long long
using namespace std;

ll dp[SIZE];
ll n, p, q, x, y;

ll get_value(ll value){
    if(value <= 0) return 1;
    if(value < SIZE && dp[value]){
        return dp[value];
    }
    else if(value < SIZE){
        return dp[value] = get_value(value/p-x) + get_value(value/q-y);
    }
    else{
        return get_value(value/p-x) + get_value(value/q-y);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>p>>q>>x>>y;
    cout<<get_value(n)<<'\n';
    return 0;
}