#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int n; 

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int c; cin>>c;
        if(c == 0){
            s.pop();
        }
        else{
            s.push(c);
        }
    }
    int res = 0;
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    cout<<res<<'\n';
    return 0;
}