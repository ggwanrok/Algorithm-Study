#include <bits/stdc++.h>

using namespace std;

long long n;
int p, q;
long long res;
map<long long, long long> m;
void input();
void func();
void output();

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    func();
    output();
    return 0;
}

long long recur(long long num){
    if(m.find(num) != m.end()) return m[num];
    if(num == 0) return 1;
    if(num == 1) return 2;
    long long val = recur(num/q) + recur(num/p);
    m.insert({num, val});
    return val;
}
void output(){
    cout<<res<<'\n';
}

void func(){
    res = recur(n);
}

void input(){
    cin>>n>>p>>q;
}