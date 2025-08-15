#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main(){
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<>());
    int mini = 0;
    for(int i=0; i<v.size(); i++){
        mini = max(mini, v[i] + i + 1);
    }
    cout<<mini+1<<'\n';
    return 0;
}