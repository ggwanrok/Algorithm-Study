#include <iostream>
using namespace std;
const int MAX_N = 247000;
bool isErased[MAX_N+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    isErased[0] = true;
    isErased[1] = true;
    for(int p = 2; p*p <= MAX_N; ++p){
            if(isErased[p]) continue;
            for(int j = p*p; j<=MAX_N; j+=p){
                isErased[j] = true;
            }
        }
    while(1){
        int t; cin>>t;
        int h = 2*t;
        if(t==0) break;
        int cnt = 0;
        
        for(int i=t+1; i<=h;++i){
            if(!isErased[i]) cnt++;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
