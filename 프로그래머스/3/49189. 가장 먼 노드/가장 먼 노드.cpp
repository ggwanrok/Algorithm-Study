#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> nodes(n+1);
    for(auto e : edge){
        nodes[e[0]].push_back(e[1]);
        nodes[e[1]].push_back(e[0]);
    }
    vector<int> is_visited(n+1, 0);
    queue<int> q;
    q.push(1);
    is_visited[1] = 1;
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        for(auto i : nodes[idx]){
            if(is_visited[i] != 0) continue;
            is_visited[i] = is_visited[idx]+1;
            q.push(i);
        }
    }
    int maxi = -1;
    
    for(auto i : is_visited){
        if(i > maxi){
            maxi = i;
            answer = 1;
        }
        else if(i == maxi){
            answer++;
        }
        
    }
    return answer;
}