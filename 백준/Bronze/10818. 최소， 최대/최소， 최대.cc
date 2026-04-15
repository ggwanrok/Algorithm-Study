#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    int n; cin>>n;
    int max =-1000005, min =1000005;
    vector <int> v;
    for(int i=0;i<n;++i){
        int a; cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<v.size();++i){
        if(max<v[i]) max = v[i];
        if(min>v[i]) min = v[i];
    }
    cout<<min<<" "<<max<<'\n';
    return 0;
}