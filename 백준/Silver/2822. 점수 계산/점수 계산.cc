#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
vector<pair<int, int>> v;
vector<int> res;
int end_res;
int main(){
    end_res = 0;
    for(int i=1; i<=8; i++){
        int a; cin>>a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<5; i++){
        res.push_back(v[i].second);
        end_res += v[i].first;
    }
    sort(res.begin(), res.end());
    cout<<end_res<<'\n';
    for(int cur : res){
        cout<<cur<<' ';
    }
    cout<<'\n';
    return 0;
}