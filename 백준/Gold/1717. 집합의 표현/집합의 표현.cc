#include <bits/stdc++.h>
using namespace std;

//union & find thema

int parent[1000001];
int n, m;

int find(int a){
    if(a != parent[a]){
         parent[a] = find(parent[a]);
    } 
    return parent[a];
 }

void union_set(int a, int b){
    if(b < a){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int par_a = find(a);
    int par_b = find(b);
    if(par_a != par_b){
        parent[par_b] = par_a;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<=n; i++){
        parent[i] = i;
    }

    for(int i=0; i<m; i++){
        int func, a, b;
        cin>>func>>a>>b;
        if(func==0){
            union_set(a, b);
        }
        else{
            if(find(a) == find(b)){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
    }


    return 0;
}