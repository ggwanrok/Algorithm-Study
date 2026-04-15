#include <bits/stdc++.h>
using namespace std;
#define MAX_DIST 250000001
/*
 * 가중치를 음수로 받아서, 벨만포드를 때러버렸을 때,
 * 음의 사이클이 있다면, -1을 출력
 * 아니라면 역추적 진행하기.
 */

void input();
bool bellman_ford(int);
void preMethod(int);

int n, m;
int route[501];
int weight[501][501];
int preRoute[501];


int main(){
    input();
    
    bool has_minus_cycle = false;
    has_minus_cycle = bellman_ford(1);
    if(has_minus_cycle){
        cout<<"-1";
    }
    else{
        preMethod(n);
    }


    return 0;
}

void input(){
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
}

bool bellman_ford(int start) {
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