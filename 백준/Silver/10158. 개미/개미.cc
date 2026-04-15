#include <bits/stdc++.h>

using namespace std;

int t;
int w, h;
int s_x, s_y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>w>>h;
    cin>>s_x>>s_y;
    cin>>t;

    //x좌표 출력파트
    if(s_x + t <= w){
        //단순 작업
        cout<<s_x+t;
    }
    else{
        if(((t-(w-s_x))/w)%2 == 0){
            //reverse
            cout<<w - ((t-(w-s_x))%w);
        }
        else{
            cout<<((t-(w-s_x))%w);
        }
    }

    cout<<' ';

    //y좌표 출력파트
    if(s_y + t <= h){
        cout<<s_y+t;
    }
    else{
        if(((t-(h-s_y))/h)%2 == 0){
            //reverse
            cout<<h - ((t-(h-s_y))%h);
        }
        else{
            cout<<((t-(h-s_y))%h);
        }
    }
    
    cout<<'\n';
    
    return 0;
}