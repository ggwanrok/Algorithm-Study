#include <bits/stdc++.h>

using namespace std;

int root;

vector<set<int>> chi;
vector<int> par;

int get_leaf(int a){
    int cnt=0;
    if(chi[a].empty()) return 1;
    for(auto son : chi[a]){
        cnt+=get_leaf(son);
    }
    return cnt;
}


int main(){

    int n;
    cin>>n;

    par.resize(n);
    chi.resize(n);
    for(int i=0; i<n; i++){
        int k; cin>>k;
        par[i] = k;
        if(k == -1){
            root = i;
            continue;
        }
        chi[k].insert(i);
    }

    int minus;
    cin>>minus;

    if(minus == root){
        cout<<0<<'\n';
        return 0;
    }

    chi[minus].clear();
    chi[par[minus]].erase(minus);

    int res = get_leaf(root);

    cout<<res<<'\n';

    return 0;
}