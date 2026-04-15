#include <iostream>

using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    for(int i=0; i<t; ++i){
        int h, w, n;
        cin>>h>>w>>n;
        int x = n/h;
        int y = n%h;
        x++;
        if(y==0){
            x--;
            y=h;
        }
        if(x<10){
            cout<<y<<"0"<<x<<'\n';
        }
        else{
            cout<<y<<x<<'\n';
        }

    }
}