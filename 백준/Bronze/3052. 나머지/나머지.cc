#include <bits/stdc++.h>

using namespace std;


set<int> s;

int main(){
    for(int i=0; i<10; i++){
        int k; cin>>k;
        s.insert(k%42);
    }
    cout<<s.size()<<'\n';
    return 0;
}