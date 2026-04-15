#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    int m; cin>>m;
    int sum =0;
    v.push_back(sum);
    for(int i=0 ; i<n; ++i){
        int k; cin>>k;
        sum+=k;
        v.push_back(sum);
    }
    for(int i=0; i<m; ++i){
        int a, b; cin>>a>>b;
        cout<<v[b] - v[a-1]<<'\n';
    }
    return 0;
}