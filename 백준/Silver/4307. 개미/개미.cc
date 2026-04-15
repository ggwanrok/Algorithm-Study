#include <iostream>
#include <set>
using namespace std;
set <int> s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for(int j=0; j<t; ++j){
        int M = 0;
        int m = 1000000;
        int w = 1000000;
        int l, n; cin>>l>>n;
        for(int i=0; i<n; ++i){
            int k; cin>>k;
            M = max(M, k);
            m = min(m, k);
            w = min(abs(l-2*k), w);
            s.insert(k*2);
        }
        if(s.end() == s.find(l-w)){
            w *= -1;
        }
        cout<<min((l-w)/2, l-(l-w)/2)<<" ";
        cout<<M-m+ max(m, l-M)<<'\n'; 
    }
    return 0;
}