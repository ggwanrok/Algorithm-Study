#include <bits/stdc++.h>

using namespace std;

//간단한 가장 긴 증가하는 수열 찾기

int n;
vector<int> v;
vector<int> lis;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }

    for(auto cur : v){
        auto iter = lower_bound(lis.begin(), lis.end(), cur);
        if(iter == lis.end()){
            lis.push_back(cur);
        }
        else{
            *iter = cur;
        }
    }

    cout<<lis.size()<<'\n';

    return 0;
}