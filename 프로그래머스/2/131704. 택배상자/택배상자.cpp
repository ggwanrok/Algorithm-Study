#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int idx = 0;
    
    for(int i=1; i<=order.size() and idx < order.size(); i++){
        if(i == order[idx]){
            answer++;
            idx++;
            while(!s.empty() and idx < order.size() and s.top() == order[idx]){
                    s.pop();
                    idx++;
                    answer++;
                }
        }
        else{
            if(s.empty() || !s.empty() and s.top() != order[idx]) s.push(i);
            else{
                while(!s.empty() and idx < order.size() and s.top() == order[idx]){
                    s.pop();
                    idx++;
                    answer++;
                }
            }
        }
        
    }
    return answer;
}