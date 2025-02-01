#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int> a, const pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int n;
    vector<pair<int, int>> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), compare);
    for(auto iter : v){
        cout<<iter.first<<' '<<iter.second<<'\n';
    }
    return 0;
}