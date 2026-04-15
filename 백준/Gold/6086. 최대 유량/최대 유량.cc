#include <bits/stdc++.h>
#define V 70
using namespace std;

/*
 * 유량의 최대치는 어차피 70만 언저리. -> int 형 써도 될듯.
 * 노드는 알파벳으로 주어진다.
 * ff 알고리즘 사용해보자.
 * bfs를 통해서 도착지까지의 경로를 구하고, 구한 뒤에 해당 경로들에 대한 유량을 업데이트해준다.
 * 전체 유량에 대한 정보는
 */

void input();
void output();
bool bfs(int, int);
void fordFulkerson(int, int);

int n;
int graph[V][V];
int parent[V];
int res_flow;

int main(){
    input();
    fordFulkerson('a'-'a', 'z'-'a');
    output();
    return 0;
}

void output(){
    cout<<res_flow;
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        char a, b;
        int x;
        cin>>a>>b>>x;
        int idx_a = (a >= 'A')?(a-'A'):(a-'a');
        int idx_b = (b >= 'A')?(b-'A'):(b-'a');
        graph[idx_a][idx_b] += x;
        graph[idx_b][idx_a] += x;
    }
}

bool bfs(int s, int e){
    // 종료지점까지 가는 경로를 탐색한다.
    bool visited[V];
    fill(&visited[0],&visited[0] + sizeof(visited), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = s;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < V; i++) {
            if (!visited[i] && graph[cur][i] > 0) {
                if (i == e) {
                    parent[i] = cur;
                    return true;
                }
                q.push(i);
                parent[i] = cur;
                visited[i] = true;
            }
        }
    }

    return false;
}

void fordFulkerson(int s, int e) {
    int u, v;

    while (bfs(s, e)) {
        //bfs 를 통해서 해당 경로 정보에 대해서는 parent를 통한 경로가 준비되어 있음.
        //해당 정보를 토대로 이동하며 유량을 업데이트 해주면 될듯.
        int path_flow = 1000000;
        for (v = e; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }

        for (v = e; v != s; v = parent[v]) {
            u = parent[v];
            graph[u][v] -= path_flow;
        }

        res_flow += path_flow;
    }
}
