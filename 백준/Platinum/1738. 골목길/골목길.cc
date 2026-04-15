#include <iostream>

using namespace std;
const int MAX_DIST = 250000001;


int n;
int route[501];
int weight[501][501];
int preRoute[501];

bool bellmanFord(int start) {
    for(int i = 1; i <= n; i++) route[i] = MAX_DIST;
    route[start] = 0;
    for(int i = 1; i <= n; i++) {
        for(int from = 1; from <= n; from++) {
            if(route[from] == MAX_DIST) continue;
            for(int to = 1; to <= n; to++) {
                if(weight[from][to] == MAX_DIST) continue;
                if(route[to] > route[from] + weight[from][to]) {
                    if(i == n && weight[to][n] != MAX_DIST) return true;
                    route[to] = route[from] + weight[from][to];
                    preRoute[to] = from;
                }
            }
        }
    }
    return false;
}

void preMethod(int s){
    if(s == 1){
        cout<<s<<" ";
    }
    else{
        preMethod(preRoute[s]);
        cout<<s<<" ";
    }
}

int main(void){
    int m;
    cin>>n>>m;

    for(int i = 1; i <= n; i++) {
            preRoute[i] =-1;
            for(int j = 1; j <= n; j++) 
                weight[i][j] = MAX_DIST;
        }

    for(int i=0; i<m; i++){
        int s, e, t;
        cin >> s >> e >> t;
        weight[s][e] = -t;
    }

    bool hasMinusCycle = false;
    hasMinusCycle = bellmanFord(1);
        
    if(hasMinusCycle){
        cout<<"-1";
    }
    else{
        preMethod(n);
    }
    

    return 0;
}