#include <bits/stdc++.h>

using namespace std;

set<string> s1;

int main(){
    int res = 0;
    int n, m;
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        s1.insert(s);
    }
    while(m--){
        string s;
        cin>>s;
        if(s1.find(s) != s1.end()){
            res++;
            continue;
        }
    }
    cout<<res<<'\n';
    return 0;
}