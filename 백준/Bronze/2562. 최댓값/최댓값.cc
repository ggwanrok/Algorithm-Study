#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);

    vector <int> v;
    for(int i=0;i<9;++i){
        int a; cin>>a;
        v.push_back(a);
    }
    int Max=0;
    for(int i=0;i<v.size();++i){
        if(Max<v[i]){
            Max = v[i];
        }
    }
    for(int i=0;i<v.size();++i){
        if(v[i] == Max){
            cout<<Max<<'\n'<<(i+1)<<'\n';
        }
    }
    return 0;
}