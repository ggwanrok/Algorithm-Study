#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

/*
넓은 범위부터 지워가는게 맞다.
짝이 맞는 순간. 해당 자리까지. 괄호자리는 '0'으로 대체.
시작 open
*/


string s;

stack<char> input_stack;

void input();
void func();
void output();
int get_pri(char);
bool is_operator(char);
bool vs_pri(char, char);


int main(){
    input();
    func();
    return 0;
}

int get_pri(char c){
    if(c == '(' || c == ')') return 0;
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
}

bool vs_pri(char c1, char c2){
    int p1 = get_pri(c1);
    int p2 = get_pri(c2);
    return p1 >= p2;
}

bool is_operator(char c){
    if(c == '+' || c=='-' || c=='*'||c=='/'||c=='('||c==')') return true;
    return false;
}

void func(){
    for(int i=0; i<s.length(); i++){
        if(!is_operator(s[i])){
            cout<<s[i];
        }
        else{
            if (s[i] == '(') {
                // '('는 무조건 스택에 push
                input_stack.push(s[i]);
            } 
            else if (s[i] == ')') {
                // ')'가 나오면 '('가 나올 때까지 pop하여 출력
                while (!input_stack.empty() && input_stack.top() != '(') {
                    cout << input_stack.top();
                    input_stack.pop();
                }
                // '(' 제거
                if (!input_stack.empty()) {
                    input_stack.pop();
                }
            } 
            else {
                // 연산자 처리
                while (!input_stack.empty() && get_pri(input_stack.top()) >= get_pri(s[i])) {
                    cout << input_stack.top();
                    input_stack.pop();
                }
                // 현재 연산자 push
                input_stack.push(s[i]);
            }
        }
    }
    // 스택에 남아 있는 연산자들 모두 출력
    while (!input_stack.empty()) {
        cout << input_stack.top();
        input_stack.pop();
    }
}

void input(){
    cin>>s;
    
}