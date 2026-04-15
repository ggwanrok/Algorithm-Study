#include <bits/stdc++.h>

using namespace std;

stack<int> a_s;
queue<int> b_q;

int main(){
    int a, b;
    int len;
    cin>>a>>b>>len;
    for(int i=0; i<len; i++){
        int k; cin>>k;
        a_s.push(k);
    }
    int mul = 1;
    int tmp = 0;
    for(int i=0; i<len; i++){
        int cur_mul = a_s.top();
        a_s.pop();
        tmp += mul * cur_mul;
        mul *= a;
    }
    int b_mul = 1;
    while(b_mul <= tmp){
        if(b_mul * b > tmp) break;
        b_mul *= b;
    }
    while(b_mul > 0){
        cout<<tmp/b_mul<<' ';
        tmp %= b_mul;
        b_mul /= b;
    }
    cout<<'\n';
    return 0;
}