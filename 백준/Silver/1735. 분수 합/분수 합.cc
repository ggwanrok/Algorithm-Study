#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b) * b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, c, d; cin >> a >> b >> c >> d;
    int mo = lcm(b, d);
    int ja = lcm(b, d)/d*c + lcm(b,d)/b*a;

    cout << ja/gcd(mo, ja) << ' ' << mo/gcd(mo, ja) << '\n';
}
