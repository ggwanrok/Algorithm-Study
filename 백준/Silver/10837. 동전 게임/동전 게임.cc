//start : 12:12
/*
영희 -> 동수의 순서로 제공된다.
해당 결과를 연출할 수 있는가? 없는가를 따져봐야 하는 구조.
이론상 가능하기 위헤서는, 최선의 상태를 따져봐야 한다
최선의 상태로 도출이 불가능한 경우라면 0 아니라면 1을 리턴

*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k, c, m, n;
    int sub;
    int coin;
    cin>>k>>c;
    while(c--){
        cin>>n>>m;
        if(n==m) cout<<1<<'\n';
        else if(n > m){
            coin = k - n + 1;
            if(n-1 <= m + coin) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        else{
            coin = k - m;
            if(m-1 <= n + coin) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
    return 0;
}