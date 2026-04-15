#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> lis;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    v.resize(n);
    for(int i=n-1; i >= 0; i--){
        int k; cin>>k;
        v[i] = k;
    }
    //역순으로 넣어줬음. 이제 lis 하면 됨.
    for(int i=0; i<v.size(); i++){
        if(lis.size() == 0){
            lis.push_back(v[i]); 
            continue;
        }
        auto iter = lower_bound(lis.begin(), lis.end(), v[i]);
        if(iter == lis.end()){
            lis.push_back(v[i]);
        }
        else{
            *iter = v[i];
        }
    }
    cout<<n-lis.size()<<'\n';
    return 0;
}