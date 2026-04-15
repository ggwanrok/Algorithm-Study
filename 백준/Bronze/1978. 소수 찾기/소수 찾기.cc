#include <iostream>
using namespace std;
int r;
bool moon(int a){
    int t=0;
    for(int i=1;i<=a;++i){
        if(a%i == 0) t++;
    }
    if(t == 2) r++;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=0; i<n;++i){
        int k; cin>>k;
        moon(k);
    }
    cout<<r<<'\n';
    return 0;
}