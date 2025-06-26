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
    int k, c, m, n;
    int sub;
    int coin;
    cin>>k>>c;
    while(c--){
        cin>>m>>n;
        if(m > n) m--;
        sub = abs(m-n);
        coin = k - max(m, n);
        
        if(n==m) cout<<1<<'\n';
        else if(coin >= sub-1) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}