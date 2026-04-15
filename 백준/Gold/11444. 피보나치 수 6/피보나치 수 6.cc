#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define DIV 1000000007


/*
f0 = 0
f1 = 1
f2 = f0 + f1
f3 = f1 + f2 = f1 + f0 + f1
f4 = f2 + f3 = f0 + f0 + f1 + f1 + f1.......
좋은 해결 방법. 이거 응용이 맞긴 한데..

행렬 곱이라는 좋은 방법이 있구나.
f(n)   = [{1, 1},  * f(n-1)
f(n-1)    {1, 0}]    f(n-2)
의 형식을 통해서 표현 가능.
또한, 이 형식은 거듭제곱 가능.
ㄴ> 1 1 1 0 인 2x2 행렬이 ^(n-1) 만큼 곱해지면.
후항은 1, 0 으로 표현이 가능해진다.
굿.
*/

ll n;
vector<vector<ll>> A = {{1, 1}, {1, 0}};
vector<vector<ll>> result = {{1, 0}, {0, 1}};
void input();
void func();
vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b);
ll fib(ll n);



int main(){
    input();
    func();
    return 0;
}


vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b){
    return {{(a[0][0]*b[0][0]+a[0][1]*b[1][0])%DIV, (a[0][0]*b[0][1]+a[0][1]*b[1][1])%DIV}, {(a[1][0]*b[0][0]+a[1][1]*b[1][0])%DIV, (a[1][0]*b[0][1]+a[1][1]*b[1][1])%DIV}};
}

ll fib(ll n){
    if(n <= 1) return n;

    n--;
    while(n){
        if(n & 1){
            result = mul(result, A);
        }
        n >>= 1;
        A = mul(A, A);
    }

    return result[0][0];
}

void func(){
    cout<<fib(n);
}

void input(){
    cin>>n;
}