#include <string>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> s;
    for(auto c : number){
        while(!s.empty() and s.top() < c - '0' and k > 0){
            s.pop();
            k--;
        }
        s.push(c-'0');
    }
    while(k-- and !s.empty()){
            s.pop();
    }
    string tmp = "";
    while(!s.empty()){
        tmp += (s.top()+'0');
        s.pop();
    }
    for(int i = tmp.length()-1; i>=0; i--){
        answer += tmp[i];
    }
    return answer;
}