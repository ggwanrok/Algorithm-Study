#include <bits/stdc++.h>
using namespace std;


int n;
int res;
vector<vector<int>> nodes;
int visited[1000001];
int dp[2][1000001]; // (얼리어답터 채택여부, 노드번호)

void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    nodes.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
}

void dfs(int node){
    visited[node] = 1;
    dp[0][node] = 0;
    dp[1][node] = 1;

    for(int nxt : nodes[node]){
        if(visited[nxt]==0){
            dfs(nxt);
            dp[0][node] += dp[1][nxt];
            dp[1][node] += min(dp[1][nxt], dp[0][nxt]);
        }
    }
}

void func(){
    dfs(1);
    res = min(dp[0][1], dp[1][1]);
}

void output(){
    cout<<res<<'\n';
}

int main(){
    input();
    func();
    output();
    return 0;
}