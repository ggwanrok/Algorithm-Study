#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

bool compare(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<0>(a) < get<0>(b);
}


int find_par(vector<int>& par, int cur){
    if(par[cur] != cur){
        return par[cur] = find_par(par, par[cur]);
    }
    else{
        return cur;
    }
}

void union_par(vector<int>& par, int a, int b){
    par[b] = find_par(par, a);
    find_par(par, b);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<tuple<int, int, int>> edge; //cost, from, to
    vector<int> par(n+1); //
    vector<int> par_cost(n+1, 0);

    for(int i=1; i<=n; i++){
        par[i] = i;
    }

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a != b) edge.push_back({c, a, b});
    }

    sort(edge.begin(), edge.end(), compare);

    for(int i=0; i<edge.size(); i++){
        int cost = get<0>(edge[i]);
        int a = get<1>(edge[i]);
        int b = get<2>(edge[i]);

        if(find_par(par, a) != find_par(par, b)){
            par_cost[a] += (cost + par_cost[par[b]]);
            par_cost[par[b]] = 0;
            union_par(par, par[a], par[b]);
        }
    }

    int res = 0;
        for(int i=1; i<=n; i++){
            res += (par_cost[i]);
        }
    cout<<res<<'\n';


}