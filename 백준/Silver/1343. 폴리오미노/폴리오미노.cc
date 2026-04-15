#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string res;
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '.'){
            if(cnt % 4 == 0){
                int kk = cnt / 4;
                for(int j=0; j<kk; j++){
                    res += "AAAA";
                }
                res += ".";
            }
            else if(cnt % 2 == 0){
                int kk = cnt / 4;
                for(int j=0; j<kk; j++){
                    res += "AAAA";
                }
                res += "BB.";
            }
            else{
                res = "-1";
                cnt = 0;
                break;
            }
            cnt = 0;
        }
        else{
            cnt++;
        }
    }

    if(res == "-1"){
        cout<<res<<'\n';
        return 0;
    }

    if(cnt != 0){
        if(cnt % 4 == 0){
            int kk = cnt / 4;
            for(int j=0; j<kk; j++){
                res += "AAAA";
            }
        }
        else if(cnt % 2 == 0){
            int kk = cnt / 4;
            for(int j=0; j<kk; j++){
                res += "AAAA";
            }
            res += "BB";
        }
        else{
            res = "-1";
        }
    }

    cout<<res<<'\n';
        
    return 0;
}
