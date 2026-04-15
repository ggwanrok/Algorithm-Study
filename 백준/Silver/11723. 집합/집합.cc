#include <iostream>
#include <set>
using namespace std;
set<int> s;
set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
void add(int x){
    s.insert(x);
}
void remove(int x){
    s.erase(x);
}
void check(int x){
    cout<<s.count(x)<<'\n';
}
void toggle(int x){
    if(s.count(x) == 0){
        s.insert(x);
    }
    else{
        s.erase(x);
    }
}
void all(){
    s = s2;
}
void empty(){
    s.clear();
}
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int m; cin>>m;
    while(m--){
        string s; cin>>s;
        if(s == "add"){
            int x; cin>>x;
            add(x);
        }
        if(s == "remove"){
            int x; cin>>x;
            remove(x);
        }
        if(s == "check"){
            int x; cin>>x;
            check(x);
        }
        if(s == "toggle"){
            int x; cin>>x;
            toggle(x);
        }
        if(s == "all"){
            all();
        }
        if(s == "empty"){
            empty();
        }
    }
    return 0;
}