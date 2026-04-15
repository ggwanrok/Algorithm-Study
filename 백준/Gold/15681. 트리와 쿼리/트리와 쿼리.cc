#include <bits/stdc++.h>

using namespace std;

int n, r, q;
int par[100001];
int node_value[100001];
queue<int> qq;
vector<vector<int>> v;

void input();
void func();
void go_root(int);
void output();

int main(void){
    std::ios_base::sync_with_stdio( false );
    std::cin.tie( NULL );
    std::cout.tie( NULL );
    input();
    func();
    output();
    return 0;
}

void output(){ 
    for(int i=0; i<q; i++){
        int a;
        cin>>a;
        cout<<node_value[a]<<'\n';
    }
    
}

void dfs(int x, int parent){
    node_value[x] = 1;
    for(int child : v[x]){
        if(par[child] == -1){
            par[child] = x;
            dfs(child, x);
            node_value[x] += node_value[child];
        }
    }
}

void func(){
    //리프가 아니라면, 쭉 타고 내려가는 dfs 를 만들고 리턴값에 +1을 해주는 방식으로 가면 될 것 같은디/
    dfs(r, par[r]);
}

void input(){
    cin>>n>>r>>q;
    for(int i=1; i<=n; i++){
        par[i] = -1;
    }
    par[r] = r;
    v.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}