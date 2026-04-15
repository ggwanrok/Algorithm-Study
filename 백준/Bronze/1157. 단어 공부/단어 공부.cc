#include <bits/stdc++.h>

using namespace std;

int alpha[27];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; cin>>s;
    for(int i=0; i<s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
    }
    memset(alpha, 0, sizeof(alpha));
    for(int i=0; i<s.length(); i++){
        alpha[s[i]-'A'] ++;
    }
    int maxi_cnt = -1;
    string maxi_value = "";
    for(int i=0; i<27; i++){
        if(maxi_cnt < alpha[i]){
            maxi_cnt = alpha[i];
            maxi_value = i+'A';
        }
        else if(maxi_cnt == alpha[i]){
            maxi_value += i+'A';
        }

    }
    if(maxi_value.length() == 1) cout<<maxi_value[0]<<'\n';
    else{
        cout<<'?'<<'\n';
    }


    return 0;
}