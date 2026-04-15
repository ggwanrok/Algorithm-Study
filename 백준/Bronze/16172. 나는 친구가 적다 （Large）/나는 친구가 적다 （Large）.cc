#include <bits/stdc++.h>

using namespace std;

string s, k;
string f_s;


void input(){
    cin >> s;
    cin >> k;

    // 숫자를 제거한 문자열 생성
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') continue;
        f_s += s[i];
    }
}


int main(){
    input();
    if(f_s.find(k) != string :: npos){
        cout<<1<<'\n';
    }
    else{
        cout<<0<<'\n';
    }
    return 0;
}
