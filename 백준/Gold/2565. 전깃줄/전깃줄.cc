#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> lis;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    vector<pair<int, int>> p;
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());
    for(auto cur : p){
        int num = cur.second;
        v.push_back(num);
    }
    //v 벡터를 가지고 lis를 돌리자.
    for(int cur : v){
        if(lis.size() == 0) {
            lis.push_back(cur);
            continue;
        }
        auto iter = lower_bound(lis.begin(), lis.end(), cur);
        if(iter != lis.end()){
            *iter = cur;
        }
        else{
            lis.push_back(cur);
        }
    }
    cout<<n-lis.size()<<'\n';
    return 0;
}