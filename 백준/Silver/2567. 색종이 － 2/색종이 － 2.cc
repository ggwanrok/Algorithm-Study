#include <bits/stdc++.h>

using namespace std;

int main(){
    int res = 0;
    int n; cin>>n;
    int paper[105][105];
    memset(paper, 0, sizeof(paper));
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        for(int i=a; i<a+10; i++){
            for(int j=b; j<b+10; j++){
                paper[i][j] = 1;
            }
        }
    }

    for(int i=1; i<=101; i++){
        for(int j=1; j<=101; j++){
            if(paper[i][j]){
                res += 4 - (paper[i-1][j] + paper[i+1][j] + paper[i][j-1] + paper[i][j+1]);
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}