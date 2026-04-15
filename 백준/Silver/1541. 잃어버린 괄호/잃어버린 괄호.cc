#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int res = 0;
    int cnt = 0;
    int mina = 0;
    string s = {};
    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt = cnt*10 + s[i] - '0';
        }
        else{
            if(mina != 0){
                res = res - cnt;
                cnt = 0;
            }
            else{
                if(s[i] == '-'){
                    mina = 1;
                }
                res = res + cnt;
                cnt = 0;
            }
        }
    }
    if(mina == 0){
        res += cnt;
    }
    else {
        res -= cnt;
    }
    cout<<res<<'\n';
    return 0;
}