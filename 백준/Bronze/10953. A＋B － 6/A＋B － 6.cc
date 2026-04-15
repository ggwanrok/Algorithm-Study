#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=0; i<t; ++i){
        string s; cin>>s;
        int a=0; int b=0;
        for(int j=0; j<s.length(); ++j){
            if(s[j]-'0'>0 && s[j]-'0'< 10 ){
                //이것은 숫자다. a와 b에 저장한다.
                if(a>0 && a<10) b = s[j]-'0';
                else a = s[j]-'0';
                }
            }
        cout<<a+b<<'\n';
    }
    return 0;
}