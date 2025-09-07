#include <bits/stdc++.h>

using namespace std;

/*
그냥 a를 추가
뒤집고 b를 추가
-> 무조건 뒤에 추가되니깐 역추적하면 될듯.
원본이냐? 판단
a : 제거
b : 제거 후, 뒤집기 한번
*/

int main(){
    string s;
    cin>>s;
    string target;
    cin>>target;
    while(target.length() > 0){
        if(target == s){
            cout<<1<<'\n';
            exit(0);
        }
        if(target[target.length()-1] == 'A'){
            target = target.substr(0, target.size()-1);
        }
        else{
            target = target.substr(0, target.size()-1);
            reverse(target.begin(), target.end());
        }
    }
    cout<<0<<'\n';
    return 0;
}