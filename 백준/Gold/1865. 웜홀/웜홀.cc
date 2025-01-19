#include <iostream>
using namespace std;
const int MAX_DIST = 25000001;

int N;
bool vis[501];
int dist[501];
int weight[501][501];

bool bellmanFord(int start) {
    for(int i = 1; i <= N; i++) dist[i] = MAX_DIST;
    vis[start] = true;
    dist[start] = 0;
    for(int i = 1; i <= N; i++) {
        for(int from = 1; from <= N; from++) {
            if(dist[from] == MAX_DIST) continue;
            for(int to = 1; to <= N; to++) {
                if(weight[from][to] == MAX_DIST) continue;
                if(dist[to] > dist[from] + weight[from][to]) {
                    if(i == N) return true;
                    vis[to] = true;
                    dist[to] = dist[from] + weight[from][to];
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int TC, M, W, S, E, T; 
    cin >> TC;
    while(TC--) {
        cin >> N >> M >> W;
        for(int i = 1; i <= N; i++) {
            vis[i] = false;
            for(int j = 1; j <= N; j++) 
                weight[i][j] = MAX_DIST;
        }
        while(M--) {
            cin >> S >> E >> T;
            if(weight[S][E] > T) weight[S][E] = weight[E][S] = T;
        }
        while(W--) {
            cin >> S >> E >> T;
            if(weight[S][E] > -T) weight[S][E] = -T;
        }

        bool hasMinusCycle = false;
        for(int start = 1; start <= N and not hasMinusCycle; start++)
            if(not vis[start]) 
                hasMinusCycle = bellmanFord(start);
        
        cout << (hasMinusCycle ? "YES\n" : "NO\n");
    } 
}