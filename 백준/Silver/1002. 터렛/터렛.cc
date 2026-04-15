#include <bits/stdc++.h>

using namespace std;

int tc;
/*
존재할 수 있는 분기.
둘이 같은 영역 : -1
내접할 때.
외접할 때.
*/
int main(){
    cin>>tc;
    while(tc--){
        int x1, x2, y1, y2, r1, r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        int min_r = min(r1, r2); //짧은 반지름
        int max_r = max(r1, r2); //긴 반지름
        int x = x2-x1; //x좌표 차이
        int y = y2-y1; //y좌표 차이
        int r = r1+r2; //반지름의 합
        int mi_r = abs(r1-r2); //반지름의 차
        int real_len = (x*x + y*y); //c*c 인 상태.
        if(x1 == x2 && y1 == y2 && r1 == r2){
            cout<<-1<<'\n';
        }
        else if(real_len > r*r){ //외부
            cout<<0<<'\n';
        }
        else if(real_len == r*r){ //외접
            cout<<1<<'\n';
        }
        else if(real_len == mi_r * mi_r){ //내접
            cout<<1<<'\n';
        }
        else if(real_len < mi_r*mi_r){ //내부
            cout<<0<<'\n';
        }
        else{
            cout<<2<<'\n';
        }
    }
    return 0;
}