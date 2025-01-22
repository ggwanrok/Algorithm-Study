#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll v1, v2;

ll lev[60];

void fill_lev();
ll count_1s(ll);
ll count_1s_rec(ll);

int main(){
    fill_lev();
    cin>>v1>>v2;
    cout<<count_1s(v2) - count_1s(v1-1)<<'\n';
    return 0;
}

// 1부터 x까지의 1의 개수를 계산하는 함수
ll count_1s(ll x) {
    if (x <= 1) return x; // 0까지의 1의 개수는 0
    int level = 0;
    ll i = 2;

    //속한 레벨 찾기.
    for(; i*2 <= x; i *= 2) level++;

    ll remaining = x - i; // 현재 레벨 내에서 남은 숫자
    //[해당 전까지 사용된 1의 갯수] + [현재 레벨에서 사용될 최상위비트 1의 갯수] + [남은 수들의 1의 갯수]
    return lev[level] + remaining + 1 + count_1s(remaining);
}

void fill_lev(){
    lev[0] = 1;
    for(int i=1; i<60; i++){
        //i단계는 전단계 2번 반복 + 전단계의 길이.
        lev[i] = 2 * lev[i-1] + ((ll) 1 << (i-1));
    }
    for(int i=1; i<60; i++){
        //누적합으로 처리.
        lev[i] += lev[i-1];
    }
}