#include <bits/stdc++.h>

using namespace std;

int paper[101][101];

int main(){
    int n;
    int res = 0;
    cin>>n;

    while(n--){
        int a, b;
        cin>>a>>b;
        for(int i=a; i<a+10; i++){
            for(int j=b; j<b+10; j++){
                paper[i][j] = 1;
            }
        }
    }
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(paper[i][j]){
                res++;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}