#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    int c1 =0;
    int c2 =0;
    int C =0;
    for(int i=0; i<n; ++i){
        string s; cin>>s;
        if(s[0] == ')'){
            cout<<"NO"<<'\n';
        }
        else{
        for(int j=0; j<s.length();++j){
            if(s[j] == '(') {
                c1++;
                C++;
            }
            else {
                if(C>0){
                c2++;
                C--;
                }
                else{
                c2++;   
                }
                }
        }
        if(c1 == c2 && C == 0){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
        c1 =0; c2 =0; C=0;
        }
    }
    return 0;
}