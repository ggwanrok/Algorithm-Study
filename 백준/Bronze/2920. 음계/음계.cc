#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(0);
    vector <int> v;
    int as =0, bs = 0;
    for(int i=0;i<8;++i){
        int a; cin>>a;
        v.push_back(a);
    }
    for(int i=1;i<8;++i){
        if(v[i-1] == v[i] -1){
            as++;
        }
        else if(v[i-1] == v[i] +1){
            bs++;
        }

    }
    if(as == 7) cout<<"ascending";
    else if(bs == 7) cout<<"descending";
    else cout<<"mixed";
    return 0;
}