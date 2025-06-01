#include <bits/stdc++.h>

using namespace std;

/*
살고싶은 호수는 전 층의 1~해당 호수만큼의 인원을 챙겨야 한다.
i호에는 i명이 사는 것이 시작.*/

int tc;

int apt[15][15]; //층수 + 호수.

void update_apt();


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    update_apt();

    cin>>tc;
    while(tc--){
        int k, n;
        cin>>k>>n;
        cout<<apt[k][n]<<'\n';
    }


    return 0;
}

void update_apt(){
    for(int i=0; i<15; i++){
        apt[0][i] = i;
    }
    for(int i=1; i<15; i++){
        for(int j=1; j<15; j++){
            apt[i][j] = apt[i][j-1] + apt[i-1][j];
        }
    }
}