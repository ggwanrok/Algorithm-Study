#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> f_list[101];
int res[101];

void input();
void func(int);

int main(void){
    input();
    for(int i=1; i<=n; i++){
        func(i);
    }
    int min_value = res[1];
    int min_idx = 1;
    for(int i=1; i<=n; i++){
        if(min_value > res[i]){
            min_value = res[i];
            min_idx = i;
        }
    }
    cout<<min_idx<<'\n';
    return 0;
}

void func(int start){
    vector<int> dist(n+1, -1);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int point = q.front();
        q.pop();
        for(auto &next : f_list[point]){
            if(dist[next] == -1){
                dist[next] = dist[point] + 1;
                q.push(next);
            }
        }
    }
    for(int i=1; i<=n; i++){
        res[start] += dist[i];
    }
}

void input(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        f_list[a].emplace_back(b);
        f_list[b].emplace_back(a);
    }
}