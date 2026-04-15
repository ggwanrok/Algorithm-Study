#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

bool comp(string a, string b){
    if(a.size() == b.size()){
        return a<b;
    }
    else{
        return a.size() < b.size();
    }
}
vector <string> v;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;++i){
        string k; cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end(), comp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<'\n';
    }
    return 0;
}