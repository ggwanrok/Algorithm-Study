#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    int t=0;
    for(int i=0; i<s.length(); ++i){
        v.push_back(s[i]-48);
    }
    if(v.size() == 2) cout<< v[0] + v[1];
    if(v.size() == 3){
        if(v[1] == 0){
            cout<<v[0]*10 + v[1] + v[2];
        }
        else{
            cout<<v[0] + v[1]*10 + v[2];
        }
    }
    if(v.size() == 4){
        cout<<v[0]*10 + v[1] + v[2]*10 + v[3];
    }
}
