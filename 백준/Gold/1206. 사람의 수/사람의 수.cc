#include <bits/stdc++.h>

using namespace std;

int n;
int res;
vector<int> aver;
void input();
void func();

int main(void){ 
    input();
    func();
    return 0;
}

void func(){
    //0점. 1명부터 시작한 경우. +1000점. +1명씩으로 늘려가야 한다.
    //b명이 참여한다고 하였을 때, a점으로 가능하느냐. 이거지.
    int pass = 0;
    int point = 0;
    int per = 0;
    for(per=1; pass < n; per++){
        pass = 0;
        point = 0;
        for(int i=0; i<n; i++){
            for(int point = 0; point/per <= aver[i]; point += 1000){
                if(aver[i] == point/per){
                    pass++;
                    break;
                }
            }
        }
    }
    cout<<per-1<<'\n';
}

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        int ii = 0;
        for(int j=0; j<s.length(); j++){
            if(s[j] == '.'){
                continue;
            }
            ii = ii * 10 + (s[j]-'0');
        }
        aver.push_back(ii);
    }
    sort(aver.begin(), aver.end());
}