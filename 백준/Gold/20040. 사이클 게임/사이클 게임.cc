#include <bits/stdc++.h>

using namespace std;

int n, m;
int res;
int flag = -1;
int par[500001];

void input();
int find(int);
bool union_set(int, int);
void output();

int main(void){
    input();
    output();
    return 0;
}

int find(int x){
    if(x != par[x]){
        par[x] = find(par[x]);
    }
    return par[x];
}

bool union_set(int i, int j){
    int i_par = find(i);
    int j_par = find(j);
    if(i_par == j_par) return true;
    if(i_par < j_par){
        par[j_par] = i_par;
    }
    else{
        par[i_par] = j_par;
    }
    return false;
}

void output(){
    cout<<res<<'\n';
}

void input(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        par[i] = i;
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin>>a>>b;
        if(flag == 1) continue;
        if(union_set(a, b)){
            res = i;
            flag = 1;
        }
    }
}