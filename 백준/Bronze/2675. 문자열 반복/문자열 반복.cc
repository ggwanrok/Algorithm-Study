#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int t; cin>>t;
    vector <char> v;
    for(int i=0; i<t; ++i){
        int r; string str; cin>>r>>str;
        for(int j=0;j<str.length();++j){
            for(int k=0;k<r;++k){
                cout<<str[j];
            }
        }
    cout<<'\n';
    }
    return 0;
}
