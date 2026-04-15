#include <bits/stdc++.h>

using namespace std;

/*
basic union find 문제.
*/

int n, m;
int res;
int parent[1005];
void input();
void output();

int find(int);
void union_group(int, int);

int main(){
    input();
    output();
    return 0;
}


void output(){
    cout<<res<<'\n';
}

void union_group(int a, int b){
    int p_a = find(a);
    int p_b = find(b);
    if(p_a != p_b){
        if(p_a < p_b){
            parent[p_b] = p_a;
        }
        else{
            parent[p_a] = p_b;
        }
        res--;
    }
}

int find(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = find(parent[node]);
}

void input(){
    cin>>n>>m;
    res = n;
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        union_group(a, b);
    }
}
