#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v;

bool cmp(int a, int b){
    if(a>b) return a<b;
    return a<b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    int sum =0;
    int max = 0;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; ++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                sum =v[i] + v[j] + v[k];
                if(sum>max && sum <=m){
                    max = sum;
                }
            }
        }
    }
    cout<<max<<'\n';

    return 0;
}