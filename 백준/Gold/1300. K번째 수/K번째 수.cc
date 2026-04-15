#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
void input();
void func();

int main(void){
    input();
    func();
    return 0;
}

void func(){
    ll le = 1, ri = (ll)n*n;
    while(le < ri){
        ll mid = (le + ri)/2;
        ll t = 0;
        for(int i=1; i<=n; i++){
            t += min(mid/i, (ll)n);
        }
        if(t<k){
            le = mid + 1;
        }
        else{
            ri = mid;
        }
    }
    cout<<ri<<'\n';
}

void input(){
    cin>>n>>k;
}