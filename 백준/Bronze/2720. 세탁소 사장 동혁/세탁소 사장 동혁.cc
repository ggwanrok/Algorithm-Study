#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int m; cin>>m;
    for(int i=0; i<m; ++i){
        int q=0, d=0, n=0, p=0;
        int k; cin>>k;
        q = k/25;
        k = k - q*25;
        d = k/10;
        k = k - d*10;
        n = k/5;
        k = k - n*5;
        p = k;
        cout<<q<<" "<<d<<" "<<n<<" "<<p<<'\n';
    }
    return 0;
} 
