#include <bits/stdc++.h>

using namespace std;

/*
a
b
a+b
a+2b
2a+3b
3a+5b
5a+8b

a에 대한 피보나치 배열을 만들고
b에 대한 피보나치 배열을 만들어

제시된 일자에 맞는 구조를 잡고 맞추기.
/-

*/

int fibo_a[31];
int fibo_b[31];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fibo_a[1] = 1;
    fibo_a[2] = 0;
    fibo_a[3] = 1;
    fibo_a[4] = 1;
    fibo_b[1] = 0;
    fibo_b[2] = 1;
    fibo_b[3] = 1;
    fibo_b[4] = 2;
    for(int i=5; i<=30; i++){
        fibo_a[i] = fibo_a[i-1]+fibo_a[i-2];
        fibo_b[i] = fibo_b[i-1]+fibo_b[i-2];
    }    
    //setting comp

    int d, k;
    cin>>d>>k;

    int a_multi = fibo_a[d];
    int b_multi = fibo_b[d];

    for(int i=1; i<=k; i++){
        for(int j=i; j<=k; j++){
            if(a_multi * i + b_multi * j == k){
                cout<<i<<'\n'<<j<<'\n';
                return 0;
            }
        }
    }
//2 26 28 54 82 136 218
    return 0;
}