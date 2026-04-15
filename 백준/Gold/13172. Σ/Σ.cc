#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m;
ll res = 0;
const ll MOD_VALUE = 1000000007;
void input();
void func();
void output();

//이진수의 시선으로 바라보기.
//지수를 이진수로 바라보고, 2로 나눈 나머지가 1일 경우, 현재 계산된 (밑이 여러번 거듭제곱된 값) 값을 곱해주고,
//0이라면 계산만 한번 더 해준다.
//이렇게 지수에 대해서 거듭제곱을 밑과 연계해서 풀이해주면, 해당 거듭제곱은 log(2)N 으로 줄일 수 있다.
ll mod_pow(ll, ll, int);

int gcd(int, int);

int main(){
    input();
    func();
    output();
    return 0;
}

void func(){
    while(m--){
        ll n, s;
        cin>>n>>s;
        res = (res + (mod_pow(n, MOD_VALUE -2, MOD_VALUE) * s) % MOD_VALUE) % MOD_VALUE;
    }
}

int gcd(int a, int b){
    if(a<b) swap(a, b);
    if(b == 0) return a;
    else return gcd(b, a%b);
}


ll mod_pow(ll base, ll exp, int mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // 지수가 홀수인 경우
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}




void input(){
    cin>>m;
}

void output(){
    cout<<res<<'\n';
}


