#include <iostream>
#include <vector>
#include <map>
using namespace std;
map <int , int> m1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=0; i<n; ++i){
        int t; cin>>t;
        if(!m1[t]){
            m1[t] =1;
        }
        else{
            m1[t]++;
        }
    }
    int m; cin>>m;
    for(int i=0; i<m; ++i){
        int t; cin>>t;
        if(!m1[t]){
            cout<<'0'<<" ";
        }
        else{
            cout<<m1[t]<<" ";
        }
    }
    return 0;
}