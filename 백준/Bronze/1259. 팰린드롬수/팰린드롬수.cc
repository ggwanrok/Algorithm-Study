#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    while(1){
    string m; cin>>m;
    if(m=="0") break;
    int len = m.length();
    int i;
    for(i=0;i<len/2;++i){
        if(m[i] != m[len-1-i]) {
            cout<<"no"<<'\n';
            break;
        }
    }
    if(i>=len/2) cout<<"yes"<<'\n';
    }
    return 0;
}