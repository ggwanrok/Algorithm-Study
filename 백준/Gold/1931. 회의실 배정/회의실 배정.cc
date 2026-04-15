#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;
bool cmp(pii a, pii b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
vector<pii> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int cnt=0;
    for(int i=0; i<n; ++i){
        int q, w; cin>>q>>w;
        v.push_back({q, w});
    }
    sort(v.begin(), v.end(), cmp);
    int t = v[0].second;
    cnt++;
    for(int i=1; i<v.size(); ++i){
        if(v[i].first >= t){
            t = v[i].second;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}