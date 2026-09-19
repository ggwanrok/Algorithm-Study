#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    int idx = 0;
    int time = 0;
    int cnt = 0;
    
    while(cnt < jobs.size()){
        
        while(idx < jobs.size() && jobs[idx][0] <= time){
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
        
        if(!pq.empty()){
            int work = pq.top().first;
            int start = pq.top().second;
            pq.pop();
            
            time += work;
            answer += time - start;
            
            cnt++;
        }
        
        else{
            time = jobs[idx][0];
        }
    }
    
    return answer / jobs.size();
}