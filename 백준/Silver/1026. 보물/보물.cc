#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<int> b;

bool compare(int a, int b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;

    for(int i=0; i<n; i++){
        int k; cin>>k; a.push_back(k);
    }
    for(int i=0; i<n; i++){
        int k; cin>>k; b.push_back(k);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compare);
    int res = 0;
    for(int i=0; i<n; i++){
        res += (a[i] * b[i]);
    }
    cout<<res<<'\n';
    return 0;
}