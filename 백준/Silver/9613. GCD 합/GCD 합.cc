#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        int t; cin>>t;
        vector<int> v; 
        long long sum =0;
        for(int j=0; j<t; ++j){
            int a; cin>>a;
            v.push_back(a);
        }
        for(int q=0; q<t-1; ++q){
            for(int w=q+1; w<t; ++w){
                sum += gcd(v[q], v[w]);
            }
        }
        cout<<sum<<'\n';
        
    }
    return 0;
}