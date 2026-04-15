#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 700000000

int res;
int n;
int dist;
vector<int> node;
vector<pair<int, int>> cost[101];

void input();
void func();
int how_much(int);

int main(){
    input();
    func();
    cout << res << '\n';
    return 0;
}

int how_much(int start){
    // 다익스트라 알고리즘 수행
    vector<int> dij(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dij[start] = 0;
    q.push({0, start});
    
    while(!q.empty()){
        int cur_node = q.top().second;
        int cur_value = q.top().first;
        q.pop();


        for(auto next : cost[cur_node]){
            int next_node = next.first;
            int next_value = next.second;

            if(dij[next_node] > dij[cur_node] + next_value){
                dij[next_node] = dij[cur_node] + next_value;
                q.push({dij[next_node], next_node});
            }
        }
    }

    int cur_res = 0;
    // dist 이하인 것들의 합산 리턴
    for(int i = 1; i <= n; i++){
        if(dij[i] <= dist){
            cur_res += node[i];
        }
    }
    return cur_res;
}

void func(){
    for(int i = 1; i <= n; i++){
        res = max(res, how_much(i));
    }
}

void input(){
    int r;
    res = 0;
    cin >> n >> dist >> r;
    node.resize(n+1);

    for(int i = 1; i <= n; i++){
        int k; 
        cin >> k;
        node[i] = k;
    }

    for(int i = 1; i <= r; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cost[a].push_back({b, c});
        cost[b].push_back({a, c});
    }
}
