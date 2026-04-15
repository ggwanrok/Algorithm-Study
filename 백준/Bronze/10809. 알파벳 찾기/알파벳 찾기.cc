#include <bits/stdc++.h>

using namespace std;

string s;
int alpha[26];

int main(){
    memset(alpha, -1, sizeof(alpha));

    cin>>s;
    for(int i=0; i<s.length(); i++){
        if(alpha[s[i]-'a'] == -1) alpha[s[i]-'a'] = i;
    }

    for(int i=0; i<26; i++){
        cout<<alpha[i]<<' ';
    }
    cout<<'\n';


    return 0;
}