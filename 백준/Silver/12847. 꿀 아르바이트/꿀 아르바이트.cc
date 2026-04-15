#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    for(int i=0; i<n; ++i){ //날마다 다른 임금을 넣어준다.
        int k; cin>>k;
        v.push_back(k);
    }
    int l =0; int r=m;
    long long sum = 0;
    for(int i=0; i<m; ++i){
        sum += v[i];
    }
    long long cul = sum;
    while(r<n && m != 0){
        cul = max(cul, sum - v[l] + v[r]);
        sum = sum - v[l] + v[r];
        l++; r++;
    }
    cout<<cul<<'\n';
    return 0;
}