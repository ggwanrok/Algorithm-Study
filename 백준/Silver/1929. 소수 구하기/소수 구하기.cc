#include <iostream>

using namespace std;
const int MAX_N = 1e6;
bool isErased[MAX_N+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    isErased[0] = true;
    isErased[1] = true;
    int m, n; cin>>m>>n;
    for(int p=2; p*p <=n; ++p){
        if(isErased[p]) continue;
        for(int j=p*p; j<=n; j+=p){
            isErased[j]=true;
        }
    }

    for(int i=m; i<=n; ++i){
       if(!isErased[i]) cout<<i<<'\n';
    }
    
}