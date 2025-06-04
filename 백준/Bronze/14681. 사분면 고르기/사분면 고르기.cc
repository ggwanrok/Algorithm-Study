#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin>>a>>b;
    if(a>0 and b>0){
        cout<<1<<'\n';
     
    }
    if(a>0 and b<0){
        cout<<4<<'\n';
    }
    if(a<0 and b>0){
        cout<<2<<'\n';
    }
    if(a<0 and b<0){
        cout<<3<<'\n';
    }
}