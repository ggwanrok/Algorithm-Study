#include <iostream>
#include <vector>
using namespace std;

    vector<int> v;
int main(){
    for(int i=0; i<5; i++){
        int k; cin>>k;
        v.push_back(k);
    }
    int res = 0;
    for(int i=0; i<5; i++){
        res += (v[i]*v[i]);
    }
    cout<<res%10<<'\n';
}