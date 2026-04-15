#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
int res = -1;
void input();
void func();
void output();

int gcd(int, int);
int lcm(int, int);

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        input();
        func();
        output();
    }
    return 0;
}

void func(){
    //n, m의 최소공배수를 구한 다음에,
    int value = lcm(n, m);
    for(int i=1; i<=value;){
        if(i % n == x && i % m == y){
            res = i;
            break;
        }
        if(i % n == x){
            i += n;
        }
        else if(i % m == y){
            i += m;
        }
        else{
            i += 1;
        }
    }
}

void input(){
    cin>>n>>m>>x>>y;
    if(x == n) x = 0;
    if(y == m) y = 0;
    res = -1;
}

void output(){
    cout<<res<<'\n';
}

int gcd(int a, int b){
    if(b == 0){
        return a; 
    }
    if(a>b){
        return gcd(b, a%b);
    }
    else{
        return gcd(a, b%a);
    }
}

int lcm(int a, int b){
    return (a * b)/gcd(a, b);
}
