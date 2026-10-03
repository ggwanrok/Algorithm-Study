#include <bits/stdc++.h>

using namespace std;

/*
지역 통과 코스트는 모두 1
다익스트라?
*/

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> edges(n+1);
    for(auto road : roads){
        edges[road[0]].push_back(road[1]);
        edges[road[1]].push_back(road[0]);
    }
    vector<int> dist(n+1, 1000000000);
    dist[destination] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, destination});
    
    while(!pq.empty()){
        int len = pq.top().first;
        int start = pq.top().second;
        pq.pop();
        
        for(int i=0; i<edges[start].size(); i++){
            if(dist[edges[start][i]] <= len) continue;
            
            if(dist[edges[start][i]] > len + 1) {
                dist[edges[start][i]] = len + 1;
                pq.push({len + 1, edges[start][i]});
            }
        }
    }
    
    for(int i=0; i<dist.size(); i++){
        if(dist[i] == 1000000000) dist[i] = -1;
    }
    
    for(auto so : sources){
        answer.push_back(dist[so]);
    }
    
    return answer;
}