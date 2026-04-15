#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
stack<int> s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        string h; cin>>h;
        if(h == "top"){
            if(s.empty()){
                cout<<"-1"<<'\n';
            }
            else{
            cout<<s.top()<<'\n';
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
            cout<<s.top()<<'\n';
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

