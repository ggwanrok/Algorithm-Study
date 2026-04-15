#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;
vector<string> res;

bool compair(string a, string b){
    return a.length() > b.length();   
}

void input();
void func();
void output();

int main(void){
    input();
    func();
    output();
    return 0;
}

void output(){
    cout<<res.size()<<'\n';

}

void func(){
    res.push_back(v[0]);
    for(int i=1; i<v.size(); i++){
        string s_i = v[i];
        int flag = 0;
        for(int j=0; j<res.size(); j++){
            flag = 0;
            for(int s = 0; s < s_i.length(); s++){
                if(s_i[s] != res[j][s]){
                    flag= -1;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        if(flag == -1){
            res.push_back(s_i);
        }
    }
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compair);
}