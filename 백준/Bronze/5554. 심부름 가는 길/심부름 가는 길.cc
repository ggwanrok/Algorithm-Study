#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int i = 4;
    int time = 0;
    while(i--){
        int t; cin>>t;
        time += t;
    }
    int min = time / 60;
    int sec = time % 60;
    cout<< min<<'\n' << sec<<'\n';
    return 0;
}