#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
그냥 인풋 자체가 짧은 구조라서 싹 돌려보면서 해도 될 것 같은데.
최대 1000개의 문자열에 대해서 스택 작업.
*/

bool is_it(char a, char b){
    if(a == '(' and b == ')') return true;
    if(a == '{' and b == '}') return true;
    if(a == '[' and b == ']') return true;
    return false;
}

bool is_closing(char a){
    if(a == ')' || a == '}' || a == ']') return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    for(int i=0; i<s.length(); i++){
        //i : 시작위치.
        stack<char> st;
        int cnt_flag = 1;
        for(int j=i; j<s.length()+i; j++){
            int idx = j % s.length();
            //idx를 기준으로 stack으로 검증해주기.
            if(st.empty()){
                if(!is_closing(s[idx])) st.push(s[idx]);
                else {
                    cnt_flag = 0;
                    break;
                }
                continue;
            }
            int cur_a = st.top();
            int cur_b = s[idx];
            if(!is_closing(cur_b)){
                st.push(cur_b);
            }
            else{
                if(is_it(cur_a, cur_b)){
                    st.pop();
                }
                else{
                    cnt_flag = 0;
                    break;
                }
            }
        }
        if(!st.empty()) continue;
        if(cnt_flag) answer++;
    }
    return answer;
}