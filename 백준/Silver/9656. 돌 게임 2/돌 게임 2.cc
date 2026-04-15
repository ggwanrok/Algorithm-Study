#include <bits/stdc++.h>

using namespace std;
int game[1001];
//  SK 기준 돌이 이만큼 남아있을 때, 이기는 구조.
//1 : SK 
//2 : CY
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    
    game[1] = 2; //패
    game[2] = 1; //승
    for(int i=3; i<=n; i++){
        game[i] = game[i-2];
    }
    string res = (game[n] == 1) ? "SK" : "CY";
    cout<<res<<'\n';
    return 0;
}