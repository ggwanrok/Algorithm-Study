#include <bits/stdc++.h>

using namespace std;

int n, m;
int res = 0;
int max_cost = 0;
// (cost, {node, node})
vector<pair<int, pair<int, int>>> way;
int parent[100001];

void input();
void func();
void output();
int get_parent(int);
void union_nodes(int, int);

int main(void){
    input();
    func();
    output();
    return 0;
}

void func(){
    for(int i = 0; i < way.size(); i++){
        int p1 = get_parent(way[i].second.first);
        int p2 = get_parent(way[i].second.second);
        if(p1 != p2){
            union_nodes(p1, p2);
            res += way[i].first;
            max_cost = (max_cost > way[i].first) ? max_cost : way[i].first;
        }
    }
}

int get_parent(int x){
    if(parent[x] == x) return x;
    else return parent[x] = get_parent(parent[x]);
}

void union_nodes(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        way.push_back({c, {a, b}});
    }
    sort(way.begin(), way.end());
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

void output(){
    cout << res-max_cost << '\n';
}
