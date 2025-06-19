#include <bits/stdc++.h>

using namespace std;

int n;
deque<int> de;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);; cout.tie(NULL);
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int val;
        if(s == "push") cin>>val;

        if(s == "push"){
            de.push_back(val);
        }
        else if(s == "pop"){
            if(de.empty()){
                cout<<-1<<'\n';
                continue;
            }
            cout<<de.front()<<'\n';
            de.pop_front();
        }
        else if(s == "size"){
            cout<<de.size()<<'\n';
        }
        else if(s == "empty"){
            cout<<de.empty()<<'\n';
        }
        else if(s == "front"){
            if(de.empty()){
                cout<<-1<<'\n';
                continue;
            }
            cout<<de.front()<<'\n';
        }
        else if(s == "back"){
            if(de.empty()){
                cout<<-1<<'\n';
                continue;
            }
            cout<<de.back()<<'\n';
        }
    }
    return 0;
}