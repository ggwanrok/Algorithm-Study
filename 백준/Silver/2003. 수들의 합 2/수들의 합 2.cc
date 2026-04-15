#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    int cnt =0;
    for(int i=0; i<n; ++i){
        int k; cin>>k;
        v.push_back(k);
    }
    int sum = v[0];
    int l =0; int r = 1;
    while(r<=n+1){
        if(sum == m){
            sum = sum - v[l]+ v[r];
            l++;
            r++;
            cnt++;
        }
        else if(sum<m){
            sum = sum + v[r];
            r++;
        }
        else{
            sum = sum - v[l];
            l++;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}