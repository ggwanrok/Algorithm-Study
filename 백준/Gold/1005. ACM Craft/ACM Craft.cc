#include <bits/stdc++.h>

using namespace std;

int tc;
int n, k;
int par[1002];
int cost[1002];
int dp_cost[1002];
vector<int> edge[1002];
vector<int> par_group;
int end_point;

void input();
void func();
void clean_haha();
void find_root();

int main(){
    input();
    while(tc--){
        func();
        clean_haha();
    }
    return 0;
}

void func(){
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        int c;
        cin>>c;
        cost[i] = c;
        dp_cost[i] = c;
        par[i] = i;
    }
    for(int i=0; i<k; i++){
        int from, to;
        cin>>from>>to;
        edge[from].push_back(to);
        par[to] = from;
    }

    cin>>end_point;
    queue<int> q;
    find_root();
    for(int i=0; i<par_group.size(); i++){
        q.push(par_group[i]);
    }
    while(!q.empty()){
        int from = q.front();
        q.pop();
        for(int i=0; i<edge[from].size(); i++){
            if(dp_cost[edge[from][i]] < dp_cost[from] + cost[edge[from][i]]){
                dp_cost[edge[from][i]] = dp_cost[from] + cost[edge[from][i]];
                q.push(edge[from][i]);
            }
            
        }
    }
    cout<<dp_cost[end_point]<<'\n';
}

void find_root(){
    for(int i=1; i<=n; i++){
        if(i == par[i]) par_group.push_back(i);
    }
}

void clean_haha(){
    for(int i=1; i<=n; i++){
        dp_cost[i] = 0;
        edge[i].clear();
    }
    par_group.clear();
}

void input(){
    cin>>tc;
}