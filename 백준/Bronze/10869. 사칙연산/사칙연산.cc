#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int a, b; cin>>a>>b;
    cout<<a+b<<'\n'<<a-b<<'\n'<<a*b<<'\n'<<a/b<<'\n'<<a%b<<'\n';
    return 0;
}