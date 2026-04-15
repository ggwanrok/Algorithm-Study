#include <bits/stdc++.h>

using namespace std;

string input_str;
string tar;
int input_len;
int tar_len;

stack<char> res;

int tar_num[10];
int tar_b_alpha[30];
int tar_s_alpha[30];

void input();
void func();
bool is_valid(char);
bool check_str(vector<char>);
void output();

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    /*
    stack에 넣어주다가, 끝문자가 나온다면 해당 끝문자로 target이 완성되는지를 판단해서 뽑는다.
    (or 다시 넣고 수행한다.)
    target과 유효한 문자인지를 판단하기 위해서, 집합을 사용하는 것이 아니라,
    숫자. 소문자. 대문자 배열을 사용한다. 이렇게 되면 시간소모를 줄일 수 있을 것.
    */
    for (int i = 0; i < input_len; i++) {
        res.push(input_str[i]);
        if (res.size() >= tar_len && input_str[i] == tar[tar_len-1]) {
            vector<char> check_vec;
            for (int j = 0; j < tar_len; j++) {
                check_vec.push_back(res.top());
                res.pop();
            }
            if (!check_str(check_vec)) {
                for (int j = check_vec.size()-1; j >= 0; j--) {
                    res.push(check_vec[j]);
                }
            }
            check_vec.clear();
        }
    }
}

bool check_str(vector<char> check_vec) {
    if (check_vec.size() != tar_len) return false;
    for (int i = 0; i < check_vec.size(); i++) {
        if (tar[i] != check_vec[check_vec.size()-1-i]) return false;
    }
    return true;
}


bool is_valid(char k){
    if(k >= '0' && k <= '9'){
        if(tar_num[k-'0'] > 0) return true;
        else return false;
    }
    else if(k >= 'a' && k <= 'z'){\
        if(tar_s_alpha[k-'a'] > 0) return true;
        else return false;
    }
    else if(k >= 'A' && k <= 'Z'){
        if(tar_b_alpha[k-'A'] > 0) return true;
        else return false;
    }
}

void input(){
    cin>>input_str;
    cin>>tar;
    input_len = input_str.length();
    tar_len = tar.length();
    for(int i=0; i<tar_len; i++){
        if(tar[i] >= '0' && tar[i] <= '9'){
            tar_num[tar[i]-'0']++;
        }
        else if(tar[i] >= 'a' && tar[i] <= 'z'){
            tar_s_alpha[tar[i]-'a']++;
        }
        else if(tar[i] >= 'A' && tar[i] <= 'Z'){
            tar_b_alpha[tar[i]-'A']++;
        }
    }
}

void output(){
    stack<char> real_res;
    while(!res.empty()){
        char k = res.top();
        real_res.push(k);
        res.pop();
    }
    if(real_res.empty()){
        cout<<"FRULA"<<'\n';
    }
    else{
        while(!real_res.empty()){
            cout<<real_res.top();
            real_res.pop();
        }
        cout<<'\n';
    }
}