#include <bits/stdc++.h>

using namespace std;

int n, m, k;

vector<int> ms;

int par[4000001];

int find(int x){
    if(x != par[x]){
        return par[x] = find(par[x]);
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>k;
    for(int i=0; i<=m; i++){
        par[i] = i;
    }
    for(int i=0; i<m; i++){
        int num; cin>>num;
        ms.push_back(num);
    }
    sort(ms.begin(), ms.end());

    for(int i=0; i<k; i++){
        //밑장뺴기 시작
        int num; cin>>num;
        auto it = upper_bound(ms.begin(), ms.end(), num);
        int idx = it - ms.begin();
        idx = find(idx);
        par[idx] = find(idx+1);
        cout<<ms[idx]<<'\n';
    }

    return 0;
}