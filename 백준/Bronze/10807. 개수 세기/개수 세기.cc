#include <bits/stdc++.h>

using namespace std;

int n, target;
vector<int> v;

int main(){
    cin>>n;
    int res = 0;
    while(n--){
        int k; cin>>k;
        v.push_back(k);
    }
    cin>>target;
    for(int i=0; i<v.size(); i++){
        if(v[i] == target) res++;
    }
    cout<<res<<'\n';
    return 0;
}