#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long n;
    cin>>n;
    long long t = 1;
    for(int i=1; i<=n; i++){
        t *= i;
    }
    cout<<t;
    return 0;
}