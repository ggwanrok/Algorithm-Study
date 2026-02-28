#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> people;

vector<int> is_visited;


int go_next(int cur_node, int cur_step){
    if(cur_step >= 5) {
       return 1;
        
    }
    for(int iter : people[cur_node]){
        if(is_visited[iter] != 1){
            is_visited[iter] = 1;
            if(go_next(iter, cur_step+1)) return 1;
            is_visited[iter] = 0;
        }
    }
    return 0;
}


int main(){
    int n, m;
    cin>>n>>m;
    people.resize(n);
    is_visited.resize(n, 0);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        people[a].push_back(b);
        people[b].push_back(a);
    }

    //the maximum case of n, m is not over than 2000 for each.
    int res = 0;
    for(int i=0; i<n; i++){
        is_visited[i] = 1;
        res = max(res, go_next(i, 1));
        is_visited[i] = 0;
    }
    cout<<res<<'\n';
    return 0;
}