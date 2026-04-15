#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int cnt =0;
    map <char, char> m;

    for(int i=0; i<n; ++i){
        string s; cin>>s;
        for(int u=1; u<s.length(); ++u){
            m[s[u]] = '5';
            }
        m[s[0]] = '1';
        for(int j=1; j<s.length(); ++j){
           if(s[j-1] == s[j]){
                m[s[j]] = '1';
            }
           else{
            if(m[s[j]] == '1'){
                cnt++;
                break;
            }
            m[s[j]] = '1';
           }
        }

    }
    cout<<n-cnt;
}
