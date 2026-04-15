#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    
    int n; cin>>n;
    for(int i=0;i<n;++i){
        int a, b; cin>>a>>b;
        cout<<a+b<<'\n';
    }
    return 0;
}