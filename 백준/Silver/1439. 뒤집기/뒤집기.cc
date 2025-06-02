#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int res1 = 0;
    int res0 = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '0'){
            if(i == 0){
                res1++;
            }
            else if(s[i-1] == '1'){
                res1++;
            }
        }
        else{
            if(i == 0){
                res0++;
            }
            else if(s[i-1] == '0'){
                res0++;
            }
        }
    }
    cout<<min(res1, res0)<<'\n';
    return 0;
}