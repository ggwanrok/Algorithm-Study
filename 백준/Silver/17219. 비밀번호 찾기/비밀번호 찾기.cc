#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n, m; cin>>n>>m;
    map<string, string> map;
    for(int i=0; i<n; ++i){
        string a, b;
        cin>>a>>b;
        map.insert({a, b});
    }
    for(int i=0;i<m;++i){
        string t; cin>>t;
        cout<<map[t]<<'\n';
    }
    return 0;
}