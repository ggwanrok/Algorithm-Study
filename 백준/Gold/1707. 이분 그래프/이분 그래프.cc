#include <bits/stdc++.h>

using namespace std;

//사이클 존재여부만 판단?

int tc;
int v, e;
vector<vector<int>> edge;
vector<int> is_visited;
vector<int> node_color;
vector<int> root;

bool is_even(int num){
    return num%2;
}

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

void union_set(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if(x > y){
            root[y] = x;
        }
        else{
            root[x] = y;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>tc;
    while(tc--){
        edge.clear();
        is_visited.clear();
        node_color.clear();
        root.clear();
        queue<int> q;
        cin>>v>>e;
        edge.resize(v+1);
        is_visited.resize(v+1);
        node_color.resize(v+1);
        root.resize(v+1);
        for(int i=1; i<=v; i++){
            root[i] = i;
        }
        for(int i=0; i<e; i++){
            int a, b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
            union_set(a, b);  // 유니온 파인드 진행
        }

        //union-find 진행 후, 남아있는 루트 노드 값만 넣어주기.
        set<int> root_nodes;
        for (int i = 1; i <= v; ++i) {
            root_nodes.insert(find(i));
        }
        for(int iter : root_nodes){
            q.push(iter);
            is_visited[iter] = 1;
            node_color[iter] = 1;
        }
        
        int flag = 0;
        while(!q.empty()) {
            int num = q.front();
            int num_color = node_color[num];
            q.pop();
            for(auto iter : edge[num]){
                //방문 하지 않았다면,
                if(is_visited[iter] == 0){
                    is_visited[iter] = 1;
                    node_color[iter] = (node_color[num]+1)%2;
                    q.push(iter);
                }
                //방문했다면 -> 노드의 색상 대조
                else{
                    if(node_color[iter] == node_color[num]){
                        flag++;
                        break;
                    }
                }
            }
            if(flag != 0) break;
        }
        if(flag == 0){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }


    return 0;
}