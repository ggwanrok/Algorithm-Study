#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
queue<int> s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        string h; cin>>h;
        if(h == "front"){
            if(s.empty()){
                cout<<"-1"<<'\n';
            }
            else{
            cout<<s.front()<<'\n';
            }
        }
        if(h == "back"){
            if(s.empty()){
                cout<<"-1"<<'\n';
            }
            else{
            cout<<s.back()<<'\n';
            }
        }
        if(h == "size"){
            cout<<s.size()<<'\n';
        }
        if(h == "empty"){
            cout<<s.empty()<<'\n';
        }
        if(h == "pop"){
            if(s.empty()){
                cout<<"-1"<<'\n';
            }
            else{
            cout<<s.front()<<'\n';
            s.pop();
            }
        }
        if(h == "push"){
            int x; cin>>x;
            s.push(x);
        }
    }
    return 0;
}
