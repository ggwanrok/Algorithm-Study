#include <iostream>
#include <cstring>
using namespace std;

int aa, bb, cc;

int dp[101][101][101];

int w(int a, int b, int c){
    if(dp[a][b][c] != -1) return dp[a][b][c];

    int res;
    if (a <= 50 or b <= 50 or c <= 50) res = 1;

    else if (a > 70 or b > 70 or c > 70) res = w(70, 70, 70);

    else if (a < b and b < c) res = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

    else res = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

    return dp[a][b][c] = res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    while(1){
        cin>>aa>>bb>>cc;
        if(aa == -1 and bb == -1 and cc == -1) break;
        cout<<"w("<<aa<<", "<<bb<<", "<<cc<<") = ";
        aa += 50;
        bb += 50;
        cc += 50;
        
        cout<<w(aa, bb, cc)<<'\n';
    }

    return 0;
}