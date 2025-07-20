/*
start - 4:30
해당 상태에서 단 하나라도 승리하는 플랜을 가지고있다면 승.
적이 모두 승리하는 패턴을 줄 경우 패.
*/

#include <bits/stdc++.h>

using namespace std;

//sy wim array
//1 : wim, 0 : loss
/*
해당 돌을 가지고 있을 때, 본인의 순소라면 이긴다는 뜻이다.
보장받는 경우는, -1, -3, -4의 경우가 모두 1이라면
상대가 주도권을 잡고 반드시 이길 수 있다는 것.
하나라도 0인게 있으면 그렇게 작업하면 이론상 이길 수 있다.*/
int sy_win[1001];


int main(){
    int n; cin>>n;
    sy_win[1] = sy_win[3]= 0;
    sy_win[2] = sy_win[4] = sy_win[5]= 1;

    for(int i=6; i<=n; i++){
        if(sy_win[i-1] == 1 and sy_win[i-3] == 1 and sy_win[i-4] == 1){
            sy_win[i] = 0;
        }
        else{
            sy_win[i] = 1;
        }
    }
    if(sy_win[n] == 0){
        cout<<"CY"<<'\n';
    }
    else{
        cout<<"SK"<<'\n';
    }

    return 0;
}