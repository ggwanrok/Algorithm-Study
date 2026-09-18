#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto i : scoville){
        pq.push(i);
    }
    while(!pq.empty()){
        int fir = pq.top();
        if(fir >= K) break;
        pq.pop();
        if(pq.empty()){
            answer = -1;
            break;
        }
        int sec = pq.top();
        pq.pop();
        pq.push(fir + 2*sec);
        answer++;
    }
    return answer;
}