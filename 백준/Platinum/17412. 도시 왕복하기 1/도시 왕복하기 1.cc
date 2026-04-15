

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//간선 방향, 총량, 흐름, 부모노드
vector<int> v[404];
int cost[404][404];
int flow[404][404];
int d[404];

int n, p;
int res;

int getFlow(int start, int end){
    while(true){
        fill(d, d+404, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int i=0; i<v[x].size(); i++){
                int y = v[x][i];
                if(cost[x][y]-flow[x][y] > 0 && d[y] == -1){
                    q.push(y);
                    d[y] = x;
                    if(y==end) break;
                }
            }
        }
        if(d[end] == -1) break;
        
        int f = 100000000;
        for(int i=end; i != start; i = d[i]){
            f = min(f, cost[d[i]][i] - flow[d[i]][i]);
        }
        for(int i=end; i != start ; i = d[i]){
            flow[d[i]][i] += f;
            flow[i][d[i]] -= f;
        }
        res += f;
    }
    return res;
}

int main(){
    cin>>n>>p;

    for(int i=0; i<p; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        cost[a][b] = 1;
    }
    cout<<getFlow(1, 2)<<'\n';

    return 0;
}