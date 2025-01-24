#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> idx;
vector<int> lis;
stack<int> res;

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}


void func(){
    lis.push_back(v[0]);
    idx[0] = 1;
    for(int i=1; i<v.size(); i++){
        if(v[i] > lis[lis.size()-1]) {
            lis.push_back(v[i]);
            idx[i] = lis.size();
        }
        else{
            auto iter = lower_bound(lis.begin(), lis.end(), v[i]);
            *iter = v[i];
            int lis_idx = iter - lis.begin() + 1;
            idx[i] = lis_idx;
        }
    }
    int res_len = lis.size();
    for(int i=n-1; i>=0; i--){
        if(res_len == idx[i]){
            res_len--;
            res.push(v[i]);
        }
    }
}


void input(){
    cin>>n;
    idx.resize(n+1,1);
    for(int i=0; i<n; i++){
        int k; cin>>k;
        v.push_back(k);
    }
}


void output(){
    cout<<lis.size()<<'\n';
    while(!res.empty()){
        cout<<res.top()<<' ';
        res.pop();
    }
    cout<<'\n';
}
