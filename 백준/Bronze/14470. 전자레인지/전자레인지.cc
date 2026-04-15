#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d, e; cin>>a>>b>>c>>d>>e;
    if(a<=0){
        cout<<abs(a)*c + d + b*e<<'\n';
    }
    else{
        cout<<(b-a)*e<<'\n';
    }
    return 0;
}
