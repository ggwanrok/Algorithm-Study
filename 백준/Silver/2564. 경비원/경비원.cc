#include <bits/stdc++.h>
using namespace std;
int N,M,d,a;
int f(int d, int a){
    if(d==1) return N*2+M-a;
    if(d==2) return a;
    if(d==3) return 2*N+M+a;
    return N+M-a;
}
int main(){
    cin>>N>>M;
    int q; cin>>q;
    vector<int> v;
    while(q--){
        cin>>d>>a;
        v.push_back(f(d,a));
    }
    cin>>d>>a;
    int A=f(d,a);
    int res=0;
    for(auto it:v){
        int k=abs(A-it);
        res+=min(k,2*N+2*M-k);
    }
    cout << res << '\n';
}