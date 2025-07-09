#include <bits/stdc++.h>
#define mod 1000000000
using namespace std;

int res_fir;
int res_sec;

int n;
int fibo[1000001];

int get_fibo(int num){
    if(fibo[num] != -1) return fibo[num];
    return fibo[num] = (get_fibo(num-2)%mod + get_fibo(num-1)%mod)%mod;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(fibo, -1, sizeof(fibo));
    fibo[0] = 0;
    fibo[1] = 1;
    
    cin>>n;
    int abs_n = abs(n);
    if(n == 0) res_fir = 0;
    else if(n < 0 && abs_n % 2 == 0) res_fir = -1;
    else res_fir = 1;
    res_sec = get_fibo(abs_n);

    cout<<res_fir<<'\n'<<res_sec<<'\n';
    return 0;
}