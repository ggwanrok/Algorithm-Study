#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int maxi = 0;
    for(int i=0; i<v.size(); i++){
        maxi = max(maxi, v[i]*(i+1));
    }
    cout<<maxi<<'\n';
    return 0;
}