#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

ll n, p, q, x, y;

map<ll, ll> is_in;

void input();
void func();
ll get_value(ll);

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    func();
    return 0;
}

ll get_value(ll idx){
    if(idx <= 0) return 1;
    if(is_in.find(idx) != is_in.end()){
        return is_in[idx];
    }
    else{
        ll value = get_value(idx/p - x) + get_value(idx/q - y);
        is_in.insert({idx, value});
        return is_in[idx];
    }
}

void func(){
    cout<<get_value(n);
}

void input(){
    cin>>n>>p>>q>>x>>y;
    is_in.clear();
}