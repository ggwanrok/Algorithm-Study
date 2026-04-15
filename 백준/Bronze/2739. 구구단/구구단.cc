#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=9;++i){
        cout<<n<<" * "<<i<<" = "<<n*i<<'\n';
    }
    return 0;
}