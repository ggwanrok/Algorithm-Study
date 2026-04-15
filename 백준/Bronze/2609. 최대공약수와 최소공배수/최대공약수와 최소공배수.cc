#include <iostream>

using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}//a,b를 이용한 재귀를 통해서 a로 최대공약수가 리턴된다.
//최소공배수는 a*b/최대공약수임을 알면 된다.
int lcm(int a, int b){
    return a*b/gcd(a, b);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q, w; cin>>q>>w;
    cout<<gcd(q, w)<<'\n'<<lcm(q, w)<<'\n';
}