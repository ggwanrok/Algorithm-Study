#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> s;
vector<int> res;
int n, m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        s.insert(k);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        int k; cin>>k;
        if(s.find(k) != s.end()) res.push_back(1);
        else res.push_back(0);
    }
    for(auto cur : res){
        cout<<cur<<' ';
    }
    cout<<'\n';
    return 0;
}