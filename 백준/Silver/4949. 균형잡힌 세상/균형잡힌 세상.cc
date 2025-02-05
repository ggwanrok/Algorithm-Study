#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while(true){
        getline(cin, s);
        if(s == ".") break;
        stack<char> ss;
        int flag = 0;
        int b_cnt = 0;
        int m_cnt = 0;
        for(char iter : s){
            if(iter == '.'){
                if(!ss.empty()){
                    flag = 1;
                }
            }
            if(iter == '('){
                ss.push('(');
            }
            if(iter == ')'){
                if(ss.empty() || ss.top() != '('){
                    flag = 1;
                    break;
                }
                else{
                    ss.pop();
                }
            }
            if(iter == '['){
               ss.push('[');
            }
            if(iter == ']'){
                if(ss.empty() || ss.top() != '['){
                    flag = 1;
                    break;
                }
                else{
                    ss.pop();
                }
            }

        }
        if(flag == 0){
            cout<<"yes"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
    }

    return 0;
}