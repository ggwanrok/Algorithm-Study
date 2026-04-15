#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
deque<int> s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        string h; cin>>h;
        if(h == "size"){
            cout<<s.size()<<'\n';
        }
        if(h == "empty"){
            cout<<s.empty()<<'\n';
        }
        if(h == "push_front"){
            int x; cin>>x;
            s.push_front(x);
            
        }
        if(h == "push_back"){
            int x; cin>>x;
            s.push_back(x);
            
        }
        if(h == "pop_front"){
            if(s.empty()){
                cout<<"-1"<<'\n';
            }
            else{
            cout<<s.front()<<'\n';
            s.pop_front();
            }
            
        }
        if(h == "pop_back"){
            if(s.empty()){
                cout<<"-1"<<'\n';
            }
            else{
            cout<<s.back()<<'\n';
            s.pop_back();
            }
            
        }
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
    }
    return 0;
}

