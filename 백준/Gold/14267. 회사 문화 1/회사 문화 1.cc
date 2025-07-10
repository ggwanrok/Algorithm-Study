/*
내가 칭찬을 받아.
그리고 난 상사의 칭찬도 받아.
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> nice_point;
vector<int> chi[100001];
vector<int> par;
vector<int> nice;

void dfs(int num){
    int value = 0;
    if(par[num] != -1){
        value += nice_point[par[num]];
    }
    value += nice[num];
    nice_point[num] += value;
    for(int node : chi[num]){
        dfs(node);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    nice_point.resize(n+1, 0);
    par.resize(n+1);
    nice.resize(n+1, 0);

    for(int i=1; i<=n; i++){
        int k; cin>>k;
        //i 아랫놈의 상사는 k
        par[i] = k; //부모는 뭐냐
        if(k < 0) continue;
        chi[k].push_back(i); //어떤 자식을 가지냐
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        nice[a] += b;
    }

    dfs(1);

    for(int i=1; i<=n; i++){
        cout<<nice_point[i]<<' ';
    }
    cout<<'\n';

    return 0;
}