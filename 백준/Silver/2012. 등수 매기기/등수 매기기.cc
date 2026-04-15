#include <bits/stdc++.h>

using namespace std;


long long res;

vector<int> v;

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for(int i=1; i<=n; i++){
        res += abs(i-v[i-1]);
    }
    cout<<res<<'\n';
    return 0;
}