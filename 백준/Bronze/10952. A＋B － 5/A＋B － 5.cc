#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
	while(1){
        int a, b; cin>>a>>b;
        if(a!=0 && b!=0){
            cout<<a+b<<'\n';
        }
        if(a==0&&b==0) break;
    }
}
