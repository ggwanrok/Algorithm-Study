#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[100005];
int parent[100005];

void input();
void func();
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void output(){
    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
}

void func(){
    queue<int> q;
    q.push(1);
    fill_n(parent, n+5, -1);
    parent[1] = 1;
    while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int i=0; i<v[par].size(); i++){
            if(parent[v[par][i]] != -1) continue;
            parent[v[par][i]] = par;
            q.push(v[par][i]);
        }
    }
}

void input(){
    cin>>n;
    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}