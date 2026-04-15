#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    double a, b; cin>>a>>b;
    cout.precision(10);
    cout<<a/b;
    return 0;
}