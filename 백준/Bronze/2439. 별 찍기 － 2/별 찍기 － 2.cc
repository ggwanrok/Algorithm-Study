#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
        for(int i=0;i<n;++i){
            for(int j=0;j+i<n-1;++j){
                cout<<" ";
            }
            for(int j=0;j<=i;++j){
                cout<<"*";
            }
            cout<<'\n';
        }
    return 0;
}