#include <bits/stdc++.h>

using namespace std;

/*
모드 연산 값이 같아야할 것 같은데.
0부터 시작하여, 1항에 대한 모드연산이 항상 
*/

int e, s, m;

int main(){
    cin>>e>>s>>m;
    int years = 0;
    int planet[3] = {e-1, s-1, m-1};
    int cnt[3] = {15, 28, 19};

    while(1){
        if(years % cnt[0] != planet[0]) years += planet[0];
        
        if(years % cnt[0] == planet[0] && years % cnt[1] == planet[1] && years % cnt[2] == planet[2]){
            cout<<years+1<<'\n';
            break;
        }
        years += 15;

    }

    return 0;
}