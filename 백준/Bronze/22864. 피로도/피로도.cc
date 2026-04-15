#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, m; cin>>a>>b>>c>>m;//쌓이는 피로도, 업무량, 줄어드는 피로도, 피로도 한계치
    int h =0;//시간
    int t = 0;//피로도 누적치
    int w = 0;//업무량 누적치
    for(h=0; h<24; ++h){
        if(t<=m-a){
            t += a;
            w += b;
        }
        else{
            t -= c;
            if(t<0){
                t = 0;
            }
        }
    }
    cout<<w;
}
