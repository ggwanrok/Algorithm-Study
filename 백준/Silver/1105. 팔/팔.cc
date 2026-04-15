#include <bits/stdc++.h>

using namespace std;

//비교분석 가능한 수의 범위는 int 형 안에서 해결이 된다.

vector<int> le;
vector<int> ri;

int res = 0;

void input();
void func();

int main(void){
    input();
    func();
    return 0;
}

void func(){
    if(le.size() != ri.size()){
        cout<<0<<'\n';
    }
    else{
        for(int i=0; i<le.size(); i++){
            if(le[i] == ri[i] && le[i] == 8){
                res++;
            }
            else if(le[i] == ri[i]){
                continue;
            }
            else{
                break;
            }
        }
        cout<<res<<'\n';
    }
}

void input(){
    string s1, s2;
    cin>>s1>>s2;
    for(int i=0; i<s1.length(); i++){
        le.push_back(s1[i]-'0');
    }
    for(int i=0; i<s2.length(); i++){
        ri.push_back(s2[i]-'0');
    }
}