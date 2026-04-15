#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num; cin>>num;

    if((num % 4 == 0 and num % 100 != 0) or num % 400 == 0){
        cout<<1<<'\n';
    }
    else cout<<0<<'\n';
    return 0;
}