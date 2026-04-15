#include <bits/stdc++.h> 

using namespace std;

/*
방문처리를 해가면서 bfs 해주기
*/

vector<int> city_is_visited;
vector<vector<int>> bridge;
int target_movement;
int start_city;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    cin>>target_movement>>start_city;
    city_is_visited.resize(n+1);
    bridge.resize(n+1);
    for(int i=0; i<m; i++){
        int prev, post;
        cin>>prev>>post;
        bridge[prev].push_back(post);
    }

    vector<int> res;

    city_is_visited[start_city] = 1;
    queue<pair<int, int>> bfs_q;
    bfs_q.push({start_city, 0});
    while(!bfs_q.empty()){
        int city_num = bfs_q.front().first;
        int cur_movement = bfs_q.front().second;
        bfs_q.pop();
        if(cur_movement == target_movement){
            res.push_back(city_num);
            continue;
        }
        for(auto iter : bridge[city_num]){
            if(city_is_visited[iter] != 1){
                city_is_visited[iter] = 1;
                bfs_q.push({iter, cur_movement+1});
            }
        }
    }

    if(res.size() == 0) cout<<-1<<'\n';
    else{
        sort(res.begin(), res.end());
        for(int cur_res : res){
            cout<<cur_res<<'\n';
        }
    }

    return 0;
}